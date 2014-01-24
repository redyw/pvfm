/*
  pvfm_temp.h

  Author:Loovee
  2013-12-31

  The MIT License (MIT)
  Copyright (c) 2013 Seeed Technology Inc.

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef __PVFM_TEMP_NEW_H__
#define __PVFM_TEMP_NEW_H__

#include <Arduino.h>
#include <Streaming.h>

#define K_TEMP          A0
#define N_TEMP          A1

#define numReadings     32
#define numReadings_2   5

#define Av_Amplifer     54.16
#define BiasVol         327         // mv

#define V_ref           5000        // mv


class PVFM_Temp{

private:
    
    int __pin_k;                                // k type temperature sensor
    int __pin_n;                                // normal temperature sensor
    
    int readings[numReadings];                  // the readings from the analog input
    int index;                                  // the index of the current reading
    long total;                                 // the running total
    int average;                                // the average
    int average_buf;                            // average data buf
    
    int temp_set;                               // temp set

private:

    // mv -> temperature
    float K_VtoT(float mV);
    // get analog data
    int getAnalog(int pin);
    
    // init buff
    void initDta();
    
    // user interfaces
    public:
    
    PVFM_Temp_new(int pin_k, int pin_n);
    // return temperature
    float get_kt();
    // push data, 1ms per time
    int pushDta();
    float get_nt();
    
    
    void setTemp(int tpr){temp_set = tpr};      // set temperature
};

#endif