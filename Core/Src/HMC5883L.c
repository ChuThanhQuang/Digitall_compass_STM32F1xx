#include "stm32f1xx_hal.h"
#include "HMC5883L.h"

#define HMC5883L_ADDRESS 0x1E



extern I2C_HandleTypeDef hi2c1;
void HMC5883L_Init(void)
{
    uint8_t data[2];

    // Set configuration register A
    data[0] = HMC5883L_REG_CONFIG_A;
    data[1] = 0x70; // 8-average, 15 Hz default, normal measurement
    HAL_I2C_Master_Transmit(&hi2c1, HMC5883L_ADDRESS, data, 2, 100);

    // Set configuration register B
    data[0] = HMC5883L_REG_CONFIG_B;
    data[1] = 0x20; // Gain = 5
    HAL_I2C_Master_Transmit(&hi2c1, HMC5883L_ADDRESS, data, 2, 100);

    // Set mode register
    data[0] = HMC5883L_REG_MODE;
    data[1] = 0x00; // Continuous measurement mode
    HAL_I2C_Master_Transmit(&hi2c1, HMC5883L_ADDRESS, data, 2, 100);
}

void HMC5883L_Read(int16_t* x, int16_t* y, int16_t* z)
{
    uint8_t data[6];

    // Read 6 bytes from the HMC5883L at the OUT_X_M register
    HAL_I2C_Mem_Read(&hi2c1, HMC5883L_ADDRESS, HMC5883L_REG_OUT_X_M, 1, data, 6, 100);

    // Combine bytes into integers
    *x = (data[0] << 8) | data[1];
    *z = (data[2] << 8) | data[3];
    *y = (data[4] << 8) | data[5];
	
}
