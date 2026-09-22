/*
* Amazon Robotics (System Design Interview):
*   Question: 
*   You are writing firmware for a weather station with an LCD display running on an ARM Cortex-M.
*   The station will eventually read from multiple sensors and updates the display at 30 Hz. For now,
*   focus on a single wind speed sensor connected over UART.
*/

#include <stdint.h>
#include <stdbool.h>

// Buffer size 
#define BUFFER_SIZE 8

//Struct to hold each wind data reading
typedef struct wind_data {
    float speed;        //m/s
    float direction;        //in degrees
} wind_data

//Circular Ring Buffer struct
typedef struct circular_buffer {
    volatile uint8_t head;
    volatile uint8_t tail;
    int count;
    wind_data circular_buffer[BUFFER_SIZE];
} circular_buffer;

void init_buffer(circular_buffer *cb) {
    cb->count = 0;
    cb->tail = 0;
    cb->head = 0;
}

void push(circular_buffer *cb, wind_data value) {
    uint18_t next = (cb->head + 1) % BUFFER_SIZE;       //increment the pointer to the circ(cb)
    cb->head = next;
    if (next == cb->tail) {
        cb->tail = (cb->tail + 1) % (BUFFER_SIZE - 1);
    }
}

bool wind_buffer_pop(circular_buffer, wind_data *value) {
    if (cb->count == 0) {
        return false;
    }
    *value = cb->circular_buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    return true;
}

// UART ISR to be called when the RX buffer is full
void UART_IRQHandler(void) {
    uint8_t raw_data[8];

    wind_data data;
    memcpy(&data.speed, raw_data, 4);
    memcpy(&data.direction, raw_data + 4, 4);

    wind_buffer_push(wind_buf, data);   //Store parsed data inside of the buffer
}

//Display task example (RTOS)
void LCD_Update_Task(void) {
    while(1) {
        wind_data latest;

        //Get the latest data from buffer
        
    }
}