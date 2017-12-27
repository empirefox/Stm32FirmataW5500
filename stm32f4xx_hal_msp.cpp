#include "stm32f4xx_hal_msp.h"
// #include "stm32f4xx_hal_hash.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "md5.h"

#ifdef __cplusplus
}
#endif

// need hardware support
// void HAL_HASH_MspInit(HASH_HandleTypeDef *hhash) {
//   /* Enable HASH clock */
//   __HAL_RCC_HASH_CLK_ENABLE();
// }

int init_mac_address(uint8_t* mac) {
  /* 16 byte buffer for MD5 hash */
  // uint8_t hash[16];

  /* magic address at which the unique device ID can be found */
  uint8_t* id = (uint8_t*)0x1FFF7A10;

  /* use md5 hash of unique device address */
  // HASH_MD5(id, 12, hash);

  // need hardware support
  //   HASH_HandleTypeDef handle;
  //   HAL_HASH_DeInit(&handle);
  //   handle.Init.DataType = HASH_DATATYPE_8B;
  //   HAL_HASH_Init(&handle);

  //   /* Compute MD5 */
  //   if (HAL_HASH_MD5_Start(&handle, id, (uint32_t)12, hash, 0xFF) != HAL_OK)
  //   {
  //     return -1;
  //   }

  // soft md5 implement
  Md5Context md5Context;
  MD5_HASH md5Hash;
  Md5Initialise(&md5Context);
  Md5Update(&md5Context, id, (uint32_t)12);
  Md5Finalise(&md5Context, &md5Hash);

  for (int i = 0; i < 6; ++i) {
    mac[i] = md5Hash.bytes[i];
  }

  /* specify as localy administrated address */
  mac[0] |= 0x2;
  /* specifiy as unicast address */
  mac[0] &= ~0x1;

  return 0;
}
