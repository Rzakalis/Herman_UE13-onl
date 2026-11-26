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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DZ|Settings", meta = (ClampMin = "0.0", ClampMax = "1000"))
	float MovementSpeed = 300.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DZ|Settings", meta = (ClampMin = "0.0", ClampMax = "100"))
	int32 Health = 100;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "DZ|Settings", meta = (ClampMin = "0.0", ClampMax = "500"))
	float Damage = 25.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "DZ|Settings")
	bool bCanSprint = true;

	UFUNCTION(BlueprintImplementableEvent, Category = "DZ|Events")
	void DisplayHealth(int32 CurrentHealth);

	UFUNCTION(BlueprintNativeEvent, Category = "DZ|Events")
	void NativeMessage();

	UFUNCTION(BlueprintCallable, Category = "DZ|Functions")
	float CalculateAverage(int32 A, int32 B);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
