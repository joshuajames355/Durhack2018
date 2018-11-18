// Fill out your copyright notice in the Description page of Project Settings.

#include "MuseInterface.h"


UMuseInterface::UMuseInterface()
{
	URL = "muse-player";
}

UMuseInterface::~UMuseInterface()
{
	process->Cancel(true);
}

void UMuseInterface::setup(int32 port)
{
	//FPlatformProcess::CreateProc(*URL,nullptr
		//,false, true, true, &pid, 0, NULL, )
	FString params = (FString("-l udp:") + FString::FromInt(port) + FString(" -D"));
	process = new FInteractiveProcess(URL, params, true);
	process->Launch();
	//process->OnOutput().BindUObject(this, &MuseInterface::PostMessage);
	process->OnOutput().BindLambda([=](const FString& message)
	{
		if (message.Contains(FString("/eeg")))
		{
			TArray <FString> dataArray;
			message.ParseIntoArray(dataArray, TEXT(" "), true);
			float answer =  FCString::Atof(*dataArray[dataArray.Num() - 1]);//(1 / 4) * (FCString::Atof(*dataArray[dataArray.Num() - 1]) + FCString::Atof(*dataArray[dataArray.Num() - 2]) + FCString::Atof(*dataArray[dataArray.Num() - 3]) + FCString::Atof(*dataArray[dataArray.Num() - 4]));
			if (answer != 0)
			{
				if(lastNAverages.Num() >= N+1)
				{ 
					lastNAverages.RemoveAt(0);
				}
				lastNAverages.Add(answer);
			}
			//GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Red, FString::SanitizeFloat(answer));
		}
	});
}

float UMuseInterface::getRollingAverage()
{
	float total = 0;
	for (float var : lastNAverages)
	{
		total += var;
	}
	return total / lastNAverages.Num();
}


