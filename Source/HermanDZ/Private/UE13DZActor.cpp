// Fill out your copyright notice in the Description page of Project Settings.


#include "UE13DZActor.h"

// Sets default values
AUE13DZActor::AUE13DZActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUE13DZActor::BeginPlay()
{
	Super::BeginPlay();

	DisplayHealth(Health);
	NativeMessage();
	
}

// Called every frame
void AUE13DZActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUE13DZActor::NativeMessage_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Native Event: C++ implementation"));
}

float AUE13DZActor::CalculateAverage(int32 A, int32 B)
{
	return (A + B) / 2.0f;
}
