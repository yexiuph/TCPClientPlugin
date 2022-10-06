// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TCPClientCommon.h"
#include "Containers/Queue.h"
#include <mutex>
/**
 *
 */
class PacketQueue
{
public:
    PacketQueue();
    ~PacketQueue();

    bool IsQueueEmpty();
    void Push(const FByteArrayRef& BufferPtr);
    FByteArrayRef Pop();

    TArray<FByteArrayRef> PopAll();

private:
    TQueue<FByteArrayRef> Queue;
    std::mutex lock;
};
