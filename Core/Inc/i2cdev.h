#ifndef I2CDEV_H
#define I2CDEV_H

#include "stm32f1xx_hal.h"

// Khai báo các hàm
HAL_StatusTypeDef I2Cdev_WriteByte(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t regAddr, uint8_t data);
HAL_StatusTypeDef I2Cdev_WriteBytes(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t regAddr, uint8_t length, uint8_t* data);
HAL_StatusTypeDef I2Cdev_ReadByte(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t regAddr, uint8_t* data);
HAL_StatusTypeDef I2Cdev_ReadBytes(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t regAddr, uint8_t length, uint8_t* data);

#endif // I2CDEV_H
