#include "i2cdev.h"
#include "stm32f1xx_hal.h"

extern I2C_HandleTypeDef hi2c1;


void I2Cdev_writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t data)
{
    HAL_I2C_Mem_Write(&hi2c1, devAddr, regAddr, I2C_MEMADD_SIZE_8BIT, &data, 1, 100);
}

void I2Cdev_readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data)
{
    HAL_I2C_Mem_Read(&hi2c1, devAddr, regAddr, I2C_MEMADD_SIZE_8BIT, data, length, 100);
}
