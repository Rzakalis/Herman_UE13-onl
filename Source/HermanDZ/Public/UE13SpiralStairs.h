#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE13SpiralStairs.generated.h"

UCLASS()
class HERMANDZ_API AUE13SpiralStairs : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AUE13SpiralStairs();

protected:
	
	virtual void OnConstruction(const FTransform& Transform) override;

	void BuildStair();

	void DestroyStairComponents();

public:	

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	float HeightBetweenStep = 100.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	float Radius = 500.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	int32 NumberOfTurns = 3;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	int32 StepsPerTurn = 5;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	UStaticMesh* StepMesh;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	bool bIsClockwise = true;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	UStaticMesh* CenterMesh;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "UE13")
	float CenterRadius = 50.0f;


private:

	TArray<UStaticMeshComponent*> mStepComponents;
	UPROPERTY()
	UStaticMeshComponent* mCenterComponent;

};
