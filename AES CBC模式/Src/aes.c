#include "main.h"

typedef struct
{
	uint8_t *ByteStr; //数据首地址 
	uint32_t Len; 	 //长度
} ByteStr_TypeDef;


typedef struct
{
	ByteStr_TypeDef	Plaintext;//明文
	ByteStr_TypeDef AAD;//附加信息
	ByteStr_TypeDef	Ciphertext;//密文
	ByteStr_TypeDef Tag;//认证标签, 固定IV为128bit（16字节）
	ByteStr_TypeDef IV;//初始向量，固定IV为96bit（12字节）
} GcmStruct_TypeDef;


void ByteExChange(uint32_t* pWord, uint32_t Length)
{
	int32_t i = 0;
	int32_t value = 0;
	uint32_t* pRam = pWord;
	for(i=0; i<Length; i++)
	{
		value = (*pRam << 24) + (((*pRam & 0xFF00) >> 8)<< 16) + (((*pRam & 0xFF0000) >> 16) << 8) + (*pRam >> 24) ;
		*pRam++= value;
	}
}


/**
  * @brief	设置加解密密钥(key0存放密钥最低32bit)
  * @param 	密钥	16/24/32字节长度的密钥  
  * @param 	长度	16/24/32          
  * @retval	None
  */
void AES_KEY_WriteEx(uint8_t *KeyIn, uint8_t Len)
{
	uint8_t i;
	__IO uint32_t Temp32;
	
	if( (Len != 16) && (Len != 24) && (Len != 32) ) return;
	
	for(i=0; i<Len; i=i+4)
	{
		Temp32 = (KeyIn[0+i]<<24)|(KeyIn[1+i]<<16)|(KeyIn[2+i]<<8)|(KeyIn[3+i]<<0);
		LL_AES_SetKeys(AES,(Len-i)/4-1,Temp32);
	}
	
}

/**
  * @brief	读取加解密密钥，第一个字存放密钥最低32bit
  * @param 	密钥	16/24/32字节长度的密钥  
  * @param 	长度	16/24/32          
  * @retval	None
  */
void AES_KEY_ReadEx(uint8_t *KeyOut, uint8_t Len)
{
	uint8_t i;
	__IO uint32_t Temp32;
	
	if( (Len != 16) && (Len != 24) && (Len != 32) ) return;
	
	for(i=0; i<Len; i=i+4)
	{
		Temp32 = LL_AES_GetKeys(AES , (Len-i)/4-1);
		KeyOut[0+i] = Temp32>>24;
		KeyOut[1+i] = Temp32>>16;
		KeyOut[2+i] = Temp32>>8;
		KeyOut[3+i] = Temp32>>0;
	}
}

/**
  * @brief	设置初始向量
  * @param 	初始向量        
  * @retval	None
  */
void AES_IVR_WriteEx(uint8_t *IVRIn)
{
	uint8_t i;
	__IO uint32_t Temp32;
	
	for(i=0; i<4*4; i=i+4)
	{
		Temp32 = (IVRIn[0+i]<<24)|(IVRIn[1+i]<<16)|(IVRIn[2+i]<<8)|(IVRIn[3+i]<<0);
		LL_AES_WriteDataToIVR(AES,(16-i)/4-1,Temp32);
	}
}

/**
  * @brief	读取初始向量
  * @param 	初始向量        
  * @retval	None
  */

void AES_IVR_ReadEx(uint8_t *IVROut)
{
	uint8_t i;
	__IO uint32_t Temp32;
	
	for(i=0; i<4*4; i=i+4)
	{
		Temp32 = LL_AES_ReadDataFromIVR(AES,(4*4-i)/4-1);
		IVROut[0+i] = Temp32>>24;
		IVROut[1+i] = Temp32>>16;
		IVROut[2+i] = Temp32>>8;
		IVROut[3+i] = Temp32>>0;	
	}
}

/**
  * @brief	设置加解密数据，16字节（128bit）分组数据输入
  * @param 	初始向量        
  * @retval	None
  */

void AES_DIN_GroupWrite_128BIT(uint8_t *DataIn)
{
	uint8_t i;
	__IO uint32_t Temp32;

	for(i=0; i<16; i=i+4)
	{
		Temp32 = (DataIn[0+i]<<24)|(DataIn[1+i]<<16)|(DataIn[2+i]<<8)|(DataIn[3+i]<<0);
		LL_AES_WriteDataToDIR(AES,Temp32);
	}
}

/**
  * @brief	加解密数据输出，16字节（128bit）分组数据输出        
  * @param 	初始向量        
  * @retval	None
  */

void AES_DOUT_GroupRead_128BIT(uint8_t *DataOut)
{
	uint8_t i;
	__IO uint32_t Temp32;
	
	for(i=0; i<16; i=i+4)
	{
		Temp32 = LL_AES_ReadDataFromDOR(AES);
		DataOut[0+i] = Temp32>>24;
		DataOut[1+i] = Temp32>>16;
		DataOut[2+i] = Temp32>>8;
		DataOut[3+i] = Temp32>>0;
	}
}

/**
  * @brief	先设置16字节（128bit）加密数据，然后再读取16字节（128bit）解密数据       
  * @param 	加密数据   
  * @param 	解密数据  
  * @retval	None
  */
ErrorStatus AES_GroupWriteAndRead_128BIT(uint8_t *DataIn, uint8_t *DataOut)
{	
	uint16_t i;
	
	/* 输入加解密数据 */
	AES_DIN_GroupWrite_128BIT(DataIn);
	
	/* 等待CCF标志置起,完成计算大约需要100个时钟周期 */
	for(i=0;i<500;i++)
	{
		if(SET == LL_AES_IsActiveFlag_Complete(AES) ) break;
	}
	/* 清CCF标志 */
	/* 读取前必须清除 */ 
	LL_AES_ClearFlag_Complete(AES);
	
	/* 读取结果 */
	AES_DOUT_GroupRead_128BIT(DataOut);
	
	if(i==500) return FAIL;
	else return PASS;
}


/**
  * @brief	先设置16字节（128bit）加密数据，然后再读取16字节（128bit）解密数据       
  * @param 	加密数据   
  * @param 	解密数据  
  * @retval	None
  */
ErrorStatus AES_GroupWriteAndRead_128BIT_IVR(uint8_t *DataIn, uint8_t *DataOut)
{	
	uint16_t i;
	
	/* 输入加解密数据 */
	AES_DIN_GroupWrite_128BIT(DataIn);
	
	/* 等待CCF标志置起,完成计算大约需要100个时钟周期 */
	for(i=0;i<500;i++)
	{
		if(SET == LL_AES_IsActiveFlag_Complete(AES) ) break;
	}
	/* 清CCF标志，读取前必须清除 */
	LL_AES_ClearFlag_Complete(AES);
	
	/* 读取结果 */
	AES_IVR_ReadEx(DataOut);
	
	if(i==500) return FAIL;
	else return PASS;
}








/**
  * @brief	AES初始化函数
	* @param  KeyLenth This parameter can be one of the following values:
  *           @arg @ref LL_AES_KEY_LENTH_IS_128BITS
  *           @arg @ref LL_AES_KEY_LENTH_IS_192BITS
  *           @arg @ref LL_AES_KEY_LENTH_IS_256BITS
	* @param	CipherMode This parameter can be one of the following values:
  *           @arg @ref LL_AES_CIPHER_ECB_MODE
  *           @arg @ref LL_AES_CIPHER_CBC_MODE
  *           @arg @ref LL_AES_CIPHER_CTR_MODE
  *           @arg @ref LL_AES_CIPHER_MULT_MODE			
	* @param	OperationMode This parameter can be one of the following values:
  *           @arg @ref LL_AES_OPERATION_MODE_ENCRYPTION
  *           @arg @ref LL_AES_OPERATION_MODE_KEY_EXTENSION
  *           @arg @ref LL_AES_OPERATION_MODE_DECRYPT
  *           @arg @ref LL_AES_OPERATION_MODE_KEY_EXTENSION_AND_DECRYPT	
	* @param	DataType This parameter can be one of the following values:
  *           @arg @ref LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED
  *           @arg @ref LL_AES_DATA_SWAP_RULE_HAIFWORD_EXCHANGE
  *           @arg @ref LL_AES_DATA_SWAP_RULE_BYTE_EXCHANGED
  *           @arg @ref LL_AES_DATA_SWAP_RULE_BIT_EXCHANGED	
  * @retval	返回错误状态，可能值：
  *       	-PASS 测试成功
  *       	-FAIL 测试失败
  */
ErrorStatus AES_Init(uint32_t KeyLenth, uint32_t CipherMode, uint32_t OperationMode, uint32_t DataType)
{
	LL_AES_InitTypeDef AES_InitStructer;
	/********************加密过程********************/
	/* 重置AES模块 */
	LL_AES_DeInit();
	/* 设置 AES_InitStruct 为默认配置 */
	LL_AES_StructInit(&AES_InitStructer);
	AES_InitStructer.KeyLenth      = KeyLenth;
  AES_InitStructer.CipherMode    = CipherMode;
  AES_InitStructer.OperationMode = OperationMode;
  AES_InitStructer.DataType      = DataType; 
	/* AES_InitStructer初始化对应外设入口地址的寄存器值 */
	return LL_AES_Init(AES,&AES_InitStructer);
}

/**
  * @brief	AES加解密处理流程
	* @param  KeyIn 密钥指针
	* @param  KeyLen 密钥长度
	* @param	IVRIn 向量指针	
	* @param	DataIn 加密输入数据指针
	* @param	DataInLen 加密数据输入长度
	* @param	DataOut 解密输出数据指针
	* @param	DataOutLen 解密输出长度
  * @retval	返回错误状态，可能值：
  *       	-PASS 测试成功
  *       	-FAIL 测试失败
  */

ErrorStatus AES_EncryptionAndDecryption(uint8_t *KeyIn, uint8_t KeyLen, uint8_t *IVRIn, uint8_t *DataIn, uint32_t DataInLen, uint8_t *DataOut, uint32_t* DataOutLen)
{
	uint32_t i;
	uint32_t result = 0;
	uint8_t TempBuf[16];
	/* 设置密钥 */
	AES_KEY_WriteEx(KeyIn,KeyLen);	
	/* CTR和CBC模式下写AES_IVRx寄存器 */
	if((*IVRIn != NULL) && (LL_AES_GetCipherMode(AES) != LL_AES_CIPHER_ECB_MODE))
	{
		AES_IVR_WriteEx(IVRIn);	
	}
	/* 启动AES */
	LL_AES_Enable(AES);

	for(i=0; i<DataInLen/16; i++)
	{
		if(LL_AES_GetCipherMode(AES) == LL_AES_CIPHER_MULT_MODE)
		{
			result = AES_GroupWriteAndRead_128BIT_IVR(DataIn + 16*i, DataOut + 16*i);
			if(result == FAIL)
				return FAIL;
		}
		else
		{
			result = AES_GroupWriteAndRead_128BIT(DataIn + 16*i, DataOut + 16*i);
			if(result == FAIL)
				return FAIL;
		}
	}
	if(DataInLen % 16)
	{
		memset(TempBuf , 0, sizeof(TempBuf));
		memcpy(TempBuf, DataIn + i*16,DataInLen - i*16);
		if(LL_AES_GetCipherMode(AES) == LL_AES_CIPHER_MULT_MODE)
		{
			result = AES_GroupWriteAndRead_128BIT_IVR(TempBuf, DataOut + i*16);
			if(result == FAIL)
				return FAIL;
		}
		else
		{
			result = AES_GroupWriteAndRead_128BIT(TempBuf, DataOut + i*16);
			if(result == FAIL)
				return FAIL;
		}
	}
	LL_AES_Disable(AES);
	return PASS;
}





/**
  * @brief	AES的ECB模式测试程序
  * @param	None
  * @retval	返回错误状态，可能值：
  *       	-PASS 测试成功
  *       	-FAIL 测试失败
  */
ErrorStatus Test_AES_ECB(void)
{
	uint8_t DataToEncrypt[16] = "1234567890";
	uint8_t AESKey[16] = "0000000000000001";
	uint8_t AESIvr[16] = "0000000000000002";
	uint8_t DataOut1[16];
	uint32_t DataOut1Len;
	uint8_t DataOut2[16];
	uint32_t DataOut2Len;
	uint32_t result;
	/* 加密 */
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_ECB_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	AES_EncryptionAndDecryption(AESKey,16,AESIvr,DataToEncrypt,16,DataOut1,&DataOut1Len);
	/* 解密 */
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_ECB_MODE,LL_AES_OPERATION_MODE_KEY_EXTENSION_AND_DECRYPT,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	AES_EncryptionAndDecryption(AESKey,16,AESIvr,DataOut1,16,DataOut2,&DataOut2Len);
	result = memcmp(DataToEncrypt,DataOut2,16);
	if (result != 0 )
	{
		return FAIL;
	}
	return PASS;

}

/**
  * @brief	AES的CTR模式测试程序
  * @param	None
  * @retval	返回错误状态，可能值：
  *       	-PASS 测试成功
  *       	-FAIL 测试失败
  */

ErrorStatus Test_AES_CTR(void)
{
	uint8_t DataToEncrypt[16] = "1234567890";
	uint8_t AESKey[16] = "0000000000000001";
	uint8_t AESIvr[16] = "0000000000000002";
	uint8_t DataOut1[16];
	uint32_t DataOut1Len;
	uint8_t DataOut2[16];
	uint32_t DataOut2Len;
	uint32_t result;
	/* 加密 */
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_CTR_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	AES_EncryptionAndDecryption(AESKey,16,AESIvr,DataToEncrypt,16,DataOut1,&DataOut1Len);
	/* 解密 */
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_CTR_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	AES_EncryptionAndDecryption(AESKey,16,AESIvr,DataOut1,16,DataOut2,&DataOut2Len);
	result = memcmp(DataToEncrypt,DataOut2,16);
	if (result != 0 )
	{
		return FAIL;
	}
	return PASS;

}

/**
  * @brief	AES的CBC模式测试程序
  * @param	None
  * @retval	返回错误状态，可能值：
  *       	-PASS 测试成功
  *       	-FAIL 测试失败
  */

ErrorStatus Test_AES_CBC(void)
{
	uint8_t DataToEncrypt[16] = "1234567890";
	uint8_t AESKey[16] = "0000000000000001";
	uint8_t AESIvr[16] = "0000000000000002";
	uint8_t DataOut1[16];
	uint32_t DataOut1Len;
	uint8_t DataOut2[16];
	uint32_t DataOut2Len;
	uint32_t result;
	/* 加密 */
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_CBC_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	AES_EncryptionAndDecryption(AESKey,16,AESIvr,DataToEncrypt,16,DataOut1,&DataOut1Len);
	/* 解密 */
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_CBC_MODE,LL_AES_OPERATION_MODE_KEY_EXTENSION_AND_DECRYPT,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	AES_EncryptionAndDecryption(AESKey,16,AESIvr,DataOut1,16,DataOut2,&DataOut2Len);
	result = memcmp(DataToEncrypt,DataOut2,16);
	if (result != 0 )
	{
		return FAIL;
	}
	return PASS;

}


/**
  * @brief	AES的MULTH模式测试程序
  * @param	None
	* @Note		MULTH模式下，数据类型DataType务必选择LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED
  * @retval	返回错误状态，可能值：
  *       	-PASS 测试成功
  *       	-FAIL 测试失败
  */

ErrorStatus Test_AES_MULTH(void)
{
	uint32_t DataToEncrypt[40] = {
				0xb41daef8,0xe7d02b66,0x9061a816,0x6a317b9e,
        0x434cbdba,0x78fe5268,0x0dd73ba7,0x3cd2e070,
        0x4ba4511b,0x58ea7aa3,0xc87b8419,0xa98756bf,
        0x4c217832,0xa58a98ca,0x5ca90d2d,0x56c29ea1,
        0xa4a583e6,0x109e5b42,0x86f49998,0x42b1c6cf,
        0x61c9895b,0x5d5cc16e,0x65adc8bb,0x7d7ec242,
        0x817fad74,0x3ebea341,0x143ae52c,0x7aa6aa83,
        0x8b6bae55,0x60a85675,0x322e7b50,0x95ad2998,
        0x7f3890ad,0x6719d313,0xab975a8a,0x2aaec3e3,
        0x30549636,0x2c2ab020,0xc1a7c503,0xb8db2fb0,
	};
	uint32_t AESKey[4] = {
				0xa7121942,0x8e9a431a,0x87deb4ab,0x9cea030e
	};

	uint32_t AESIvr[4] = {
				0x7c776dd9,0x444bccc4,0xc9367885,0x4be99b67
	};
	
	uint32_t Result[40] = {
				0xc26d7314,0x7ef12993,0x7924d021,0x49a288bd,
        0xb8074a26,0x6080b4ef,0x9dd6f65c,0xa1316074,
        0xe64ce340,0x69d9e114,0x22f96a6f,0xa9e6b908,
        0x0bfe4c53,0x87ebab8a,0x3caf1e52,0x6c7779e0,
        0xb0ad8400,0x174fe560,0x052640e8,0x67ad35a1,
        0x35478633,0x03653c71,0x1fcec3e7,0x047e32cd,
        0x3cb75b8e,0x9102fcc4,0xfdc594e5,0xc7f52620,
        0x674bd35d,0x6ea2885f,0x70efa246,0x4304712d,
        0x1a1a0bb7,0xadff3ae5,0x7ce6ae15,0xaaf7e174,
        0xd0287e4d,0x531de812,0x22ab2933,0x50173ddb,
	};
	
	uint32_t DataOut1[40];
	uint32_t DataOut1Len;
	uint32_t result;

	ByteExChange(DataToEncrypt,40);
	ByteExChange(AESKey,4);
	ByteExChange(AESIvr,4);
	ByteExChange(Result,40);
	
		/* 加密 */
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_MULT_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	AES_EncryptionAndDecryption((uint8_t*)AESKey,16,(uint8_t*)AESIvr,(uint8_t*)DataToEncrypt,40*4,(uint8_t*)DataOut1,&DataOut1Len);
	result = memcmp(DataOut1,Result,40*4);
	if(result != 0)
	{
		return FAIL;
	}
	return PASS;

}


static void BitExchange128(uint8_t* BufOut, uint8_t* BufIn)
{
	uint8_t i,j,Temp08A,Temp08B;
	uint8_t Buf[16];
	
	for(i=0; i<16; i++)
	{
		Temp08A = BufIn[i];
		Temp08B = 0;
		for(j=0; j<8; j++)
		{
			Temp08B = Temp08B<<1;
			if(Temp08A&0x01)
			{
				Temp08B |= 0x01;
			}
			Temp08A = Temp08A>>1;
		}
		Buf[16-i-1] = Temp08B;
	}
	memcpy(BufOut, Buf, 16);
}

/**
  * @brief	GCM数据打包处理
	* @param	DataIn 加密输入数据指针
  * @retval	返回错误状态，可能值：
  *       	-PASS 测试成功
  *       	-FAIL 测试失败
  */

ErrorStatus AES_GCM_Encryption(uint8_t *DataIn, uint32_t DataInLen)
{
	uint32_t i,j;
	uint8_t buf1[16],buf2[16];
	for(i = 0; i< DataInLen / 16; i++)
	{
			BitExchange128(buf1,DataIn + 16*i);
			AES_DIN_GroupWrite_128BIT(buf1);
			for(j=0;j<500;j++)
			{
				if(SET == LL_AES_IsActiveFlag_Complete(AES) ) break;
			}
			LL_AES_ClearFlag_Complete(AES);
	}
	if(DataInLen % 16)
	{
		memset(buf1 , 0, sizeof(buf1));
		memcpy(buf1, DataIn + i*16,DataInLen - i*16);
		BitExchange128(buf2,buf1);
		AES_DIN_GroupWrite_128BIT(buf2);
		for(j=0;j<500;j++)
		{
			if(SET == LL_AES_IsActiveFlag_Complete(AES) ) break;
		}
		LL_AES_ClearFlag_Complete(AES);
	}
	return PASS;
}

/* GcmH 计算*/
ErrorStatus GcmHCalc(uint8_t* GcmH, uint8_t* AESKey)
{
	ErrorStatus Result;
	uint8_t Buf[16];
	uint32_t DataOut1Len;
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_ECB_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	memset(Buf, 0, 16);
	Result = AES_EncryptionAndDecryption((uint8_t*)AESKey,16,NULL,(uint8_t*)Buf,16,GcmH,&DataOut1Len);
	return Result;
}

/* 获取附加信息长度和密文长度转化成的数组*/
void GetGcmLength16Buffer(GcmStruct_TypeDef* GcmStruct,uint8_t* OutBuffer)
{
	uint8_t Buf[16];
	uint32_t Temp32;
	memset(Buf, 0, 16);
	Temp32 = GcmStruct->AAD.Len * 8;
	Buf[4] = Temp32>>24;
	Buf[5] = Temp32>>16;
	Buf[6] = Temp32>>8;
	Buf[7] = Temp32>>0;
	
	Temp32 = GcmStruct->Ciphertext.Len * 8;
	Buf[12] = Temp32>>24;
	Buf[13] = Temp32>>16;
	Buf[14] = Temp32>>8;
	Buf[15] = Temp32>>0;
	memcpy(OutBuffer,Buf,16);
}

/* Hash 计算*/
ErrorStatus GcmHash(uint8_t* HashRes, GcmStruct_TypeDef* GcmStruct, uint8_t* HashH)
{
	ErrorStatus Result;
	uint8_t Buf[16],AESKey[16],AESIvr[16];
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_MULT_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	
	BitExchange128(AESKey, HashH);
	memset(AESIvr, 0, 16);
	/* 设置密钥 */
	AES_KEY_WriteEx(AESKey,16);	
	/* IVR 初始化*/
	AES_IVR_WriteEx(AESIvr);	
	/* 启动AES */
	LL_AES_Enable(AES);
	
	Result = AES_GCM_Encryption(GcmStruct->AAD.ByteStr, GcmStruct->AAD.Len);
	if(Result == FAIL)
		return FAIL;
	
	Result = AES_GCM_Encryption(GcmStruct->Ciphertext.ByteStr, GcmStruct->Ciphertext.Len);
	if(Result == FAIL)
		return FAIL;
	
	GetGcmLength16Buffer(GcmStruct,Buf);
	
	Result = AES_GCM_Encryption(Buf, 16);
	if(Result == FAIL)
		return FAIL;
	
	/* 读取结果 */
	AES_IVR_ReadEx(Buf);
	BitExchange128(HashRes, Buf);
	LL_AES_Disable(AES);
	return Result;
}

/* GCM CTR 计算*/
ErrorStatus GcmCTR(ByteStr_TypeDef* DataOut, ByteStr_TypeDef* DataIn, uint8_t* IV, uint8_t* Key)
{
	ErrorStatus Result;
	AES_Init(LL_AES_KEY_LENTH_IS_128BITS,LL_AES_CIPHER_CTR_MODE,LL_AES_OPERATION_MODE_ENCRYPTION,LL_AES_DATA_SWAP_RULE_NOT_EXCHANGED);
	Result = AES_EncryptionAndDecryption((uint8_t*)Key,16,IV,(uint8_t*)DataIn->ByteStr,DataIn->Len,DataOut->ByteStr,&DataOut->Len);
	return Result;
}


/* GCM加密流程处理 */
ErrorStatus GcmEncrypt(GcmStruct_TypeDef* GcmStruct, uint8_t* Key)
{
	uint8_t Jzero[16];
	uint8_t HashRes[16];
	uint8_t HashH[16];
	ByteStr_TypeDef TmpBS;
//uint8_t testHashRes[16] = {0x7d, 0x82, 0x5c, 0x3b, 0xe4, 0xa7, 0x7c, 0x3f, 0xcc, 0x05, 0x6b, 0x6b, 0xbe, 0xe4, 0x14, 0xe5};

	/* 初始向量处理 */
	memset(Jzero, 0 ,16);
	memcpy(Jzero, GcmStruct->IV.ByteStr, 12);
	Jzero[15] = 2;
	
	/* 明文ctr加密处理 */
	GcmCTR(&GcmStruct->Ciphertext, &GcmStruct->Plaintext, Jzero, Key);
	
	/* 计算ghash处理 */
	GcmHCalc(HashH, Key);
	GcmHash(HashRes, GcmStruct, HashH);

	/* 计算AuthTag */
	Jzero[15] = 1;
	TmpBS.ByteStr = HashRes;
	TmpBS.Len = 16;
	GcmCTR(&GcmStruct->Tag, &TmpBS, Jzero, Key);

	return PASS;
}

/* GCM解密流程处理 */
ErrorStatus GcmDecrypt(GcmStruct_TypeDef* GcmStruct, uint8_t* Key)
{
	uint8_t i;
	uint8_t Jzero[16];
	uint8_t HashRes[16];
	uint8_t HashH[16];
	uint8_t TmpTag[16];
	ByteStr_TypeDef TmpBS;
	ByteStr_TypeDef TmpBSTag;

	/* 初始向量处理 */
	memset(Jzero, 0 ,16);
	memcpy(Jzero, GcmStruct->IV.ByteStr, 12);
	Jzero[15] = 1;
	
	/* 计算ghash处理 */
	GcmHCalc(HashH, Key);
	GcmHash(HashRes, GcmStruct, HashH);

	/* 计算AuthTag */
	Jzero[15] = 1;
	TmpBS.ByteStr = HashRes;
	TmpBS.Len = 16;
	TmpBSTag.ByteStr = TmpTag;
	TmpBSTag.Len = 16;
	GcmCTR(&TmpBSTag, &TmpBS, Jzero, Key);
	
	/* 比较AuthTag */
	for(i=0; i<12; i++)
	{
		if(TmpBSTag.ByteStr[i] != GcmStruct->Tag.ByteStr[i]) break;
	}
	if(i != 12) 
		return FAIL;
	
	/* ctr加密处理 */
	Jzero[15] = 2;
	GcmCTR(&GcmStruct->Plaintext, &GcmStruct->Ciphertext, Jzero, Key);
	
	return PASS;
}

ErrorStatus Test_AES_GCM(void)
{
	int Result = -1;
	GcmStruct_TypeDef TestGCM;
	uint8_t DataToEncrypt[13] = {0xC0, 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x01, 0x00, 0x00, 0xFF, 0x02, 0x00};
	uint8_t AAD[17] = {0x30, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF};
	uint8_t AESKey[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
	uint8_t IV[12] = {0x4D, 0x4D, 0x4D, 0x00, 0x00, 0xBC, 0x61, 0x4E, 0x01, 0x23, 0x45, 0x67};
		

	uint8_t EncryptBuf[16];
	uint8_t Tag[16];
	uint8_t DecryptBuf[16];	
	
	TestGCM.AAD.ByteStr = AAD;
	TestGCM.AAD.Len = 17;
	
	TestGCM.Plaintext.ByteStr = DataToEncrypt;
	TestGCM.Plaintext.Len = 13;
	
	TestGCM.IV.ByteStr = IV;
	TestGCM.IV.Len = 12;
	
	TestGCM.Ciphertext.ByteStr = EncryptBuf;
	TestGCM.Ciphertext.Len = 13;
	
	TestGCM.Tag.ByteStr = Tag;
	TestGCM.Tag.Len = 16;
	
	GcmEncrypt(&TestGCM,AESKey);

	TestGCM.Plaintext.ByteStr = DecryptBuf;
	TestGCM.Plaintext.Len = 13;
	
	Result = GcmDecrypt(&TestGCM,AESKey);
	if(Result == FAIL)
	{
		return FAIL;
	}
	
	Result = memcmp(DecryptBuf,DataToEncrypt,sizeof(DataToEncrypt));
	if(Result != 0)
	{
		return FAIL;
	}
	
	return PASS;
}
