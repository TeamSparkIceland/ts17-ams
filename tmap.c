#include "tmap.h"
#include <stdint.h>
#include <stdio.h>

const float temperature_map[201] = {
		3.64,
		3.62,
		3.60,
		3.58,
		3.56,
		3.54,
		3.52,
		3.49,
		3.47,
		3.45,
		3.43,
		3.41,
		3.38,
		3.36,
		3.34,
		3.32,
		3.29,
		3.27,
		3.25,
		3.22,
		3.20,
		3.18,
		3.16,
		3.13,
		3.11,
		3.09,
		3.06,
		3.04,
		3.02,
		2.99,
		2.97,
		2.94,
		2.92,
		2.90,
		2.87,
		2.85,
		2.83,
		2.80,
		2.78,
		2.76,
		2.73,
		2.71,
		2.69,
		2.66,
		2.64,
		2.62,
		2.59,
		2.57,
		2.55,
		2.52,
		2.50,
		2.48,
		2.45,
		2.43,
		2.41,
		2.39,
		2.36,
		2.34,
		2.32,
		2.29,
		2.27,
		2.25,
		2.23,
		2.21,
		2.18,
		2.16,
		2.14,
		2.12,
		2.10,
		2.08,
		2.05,
		2.03,
		2.01,
		1.99,
		1.97,
		1.95,
		1.93,
		1.91,
		1.89,
		1.87,
		1.85,
		1.83,
		1.81,
		1.79,
		1.77,
		1.75,
		1.73,
		1.71,
		1.69,
		1.67,
		1.66,
		1.64,
		1.62,
		1.60,
		1.58,
		1.56,
		1.55,
		1.53,
		1.51,
		1.49,
		1.48,
		1.46,
		1.44,
		1.43,
		1.41,
		1.39,
		1.38,
		1.36,
		1.35,
		1.33,
		1.32,
		1.30,
		1.28,
		1.27,
		1.25,
		1.24,
		1.22,
		1.21,
		1.20,
		1.18,
		1.17,
		1.15,
		1.14,
		1.13,
		1.11,
		1.10,
		1.09,
		1.07,
		1.06,
		1.05,
		1.04,
		1.02,
		1.01,
		1.00,
		0.99,
		0.97,
		0.96,
		0.95,
		0.94,
		0.93,
		0.92,
		0.91,
		0.89,
		0.88,
		0.87,
		0.86,
		0.85,
		0.84,
		0.83,
		0.82,
		0.81,
		0.80,
		0.79,
		0.78,
		0.77,
		0.76,
		0.75,
		0.74,
		0.74,
		0.73,
		0.72,
		0.71,
		0.70,
		0.69,
		0.68,
		0.68,
		0.67,
		0.66,
		0.65,
		0.64,
		0.64,
		0.63,
		0.62,
		0.61,
		0.60,
		0.60,
		0.59,
		0.58,
		0.58,
		0.57,
		0.56,
		0.56,
		0.55,
		0.54,
		0.54,
		0.53,
		0.52,
		0.52,
		0.51,
		0.50,
		0.50,
		0.49,
		0.49,
		0.48,
		0.47,
		0.47,
		0.46,
		0.46,
		0.45,
		0.45,
		0.44
};

// Sequential search: O(n) = n
float LookupTemperature(float voltage) {
    uint8_t index = 0;
    if (voltage > temperature_map[0])
        return (float)(201/2);
    if (voltage < temperature_map[201-1])
        return 0;
    while (voltage < temperature_map[index])
        index++;
    return (float)(index/2);
}
