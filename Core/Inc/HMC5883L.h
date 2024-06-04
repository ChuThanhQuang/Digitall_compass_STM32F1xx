#ifndef HMC5883L_H
#define HMC5883L_H
#define I2C hi2c1
#define HMC5883L_ADDRESS              0x1E // this device only has one address
#define HMC5883L_DEFAULT_ADDRESS    (HMC5883L_ADDRESS<<1) // 0x3C

//#define HMC5883L_ADDRESS              (0x1E)
#define HMC5883L_REG_CONFIG_A         (0x00)
#define HMC5883L_REG_CONFIG_B         (0x01)
#define HMC5883L_REG_MODE             (0x02)
#define HMC5883L_REG_OUT_X_M          (0x03)
#define HMC5883L_REG_OUT_X_L          (0x04)
#define HMC5883L_REG_OUT_Z_M          (0x05)
#define HMC5883L_REG_OUT_Z_L          (0x06)
#define HMC5883L_REG_OUT_Y_M          (0x07)
#define HMC5883L_REG_OUT_Y_L          (0x08)
#define HMC5883L_REG_STATUS           (0x09)
#define HMC5883L_REG_IDENT_A          (0x0A)
#define HMC5883L_REG_IDENT_B          (0x0B)
#define HMC5883L_REG_IDENT_C          (0x0C)
#define HMC5883L_REG_DATA_X_MSB 0x03

#include "i2cdev.h"

void HMC5883L_Init(void);
void HMC5883L_setMode(uint8_t mode);
void HMC5883L_setGain(uint8_t gain);
void HMC5883L_setDataRate(uint8_t rate);
void HMC5883L_Read(int16_t* x, int16_t* y, int16_t* z);
uint8_t HMC5883L_testConnection(void);
#endif // HMC5883L_H
