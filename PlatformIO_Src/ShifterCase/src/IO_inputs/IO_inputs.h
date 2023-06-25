#ifndef RTWTYPES_H
#define RTWTYPES_H

#include "Arduino.h"

class IOinput
{
    public:
        void InitInputs(void);
        void FastCyclic(void);
    private:
        
        struct IOInputs_MaxGearLimit
        {
            uint8_t MaxGearPin;
            uint8_t MaxGeraLimit;

        };
        
        struct IOInputs_Data
        {
            uint8_t ShiftUpRequest;
            uint8_t ShiftDownRequest;
            uint8_t ResetCount;
        };

}