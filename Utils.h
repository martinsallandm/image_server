#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include <PvDevice.h>
#include <PvDeviceGEV.h>
#include <PvDeviceU3V.h>
#include <PvStream.h>
#include <PvStreamGEV.h>
#include <PvStreamU3V.h>
#include <PvPipeline.h>
#include <PvBuffer.h>
#include <PvBufferWriter.h>



#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define BUFFER_COUNT 16
#define CAM_IP "10.194.64.117"
#define COUNTER_FILE "counter.txt"



void logPrintf(const char *level, const char *msg);
void logError(const char *level, const char *msg);
int loadCounter();
void writeCounter(int imageCounter);


// MyPipelineEventSink class


class MyPipelineEventSink : PvPipelineEventSink {

public:
    int isReady;

    void OnBufferReady(PvPipeline *aPipeline);

    void OnStop(PvPipeline *aPipeline);

    void OnStart(PvPipeline *aPipeline);
}; 


#endif // __UTILS_H__