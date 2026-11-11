#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

USTRUCT(Blueprintable)
struct FMyStruct
{
	GENERATED_BODY()

	float Value;
	FVector Position;
};

UCLASS(Blueprintable)
class HERMANDZ_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:	
	

};
