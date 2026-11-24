// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE13DZActor.generated.h"

UCLASS()
class HERMANDZ_API AUE13DZActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUE13DZActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DZ|Settings")
	float MovementSpeed = 300.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
