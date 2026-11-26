#include "UE13SpiralStairs.h"

AUE13SpiralStairs::AUE13SpiralStairs()
{
	PrimaryActorTick.bCanEverTick = false;
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    mCenterComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CenterCylinder"));
    mCenterComponent->SetupAttachment(RootComponent);
    mCenterComponent->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AUE13SpiralStairs::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	BuildStair();
}

void AUE13SpiralStairs::BuildStair()
{
    DestroyStairComponents();

    // Проверяем наличие меша ступеней
    if (!StepMesh)
    {
        return;
    }

    int32 TotalSteps = FMath::Max(1, NumberOfTurns * StepsPerTurn);
    float AngleStep = 360.0f / FMath::Max(1, StepsPerTurn);

    // Создаём центральный цилиндр
    if (CenterMesh && mCenterComponent)
    {
        mCenterComponent->SetStaticMesh(CenterMesh);

        FVector MeshExtent = CenterMesh->GetBounds().BoxExtent;
        float StepHalfHeight = StepMesh->GetBounds().BoxExtent.Z;

        float CylinderHeight =
            (TotalSteps - 1) * HeightBetweenStep + StepHalfHeight * 2.0f;

        if (MeshExtent.X > KINDA_SMALL_NUMBER &&
            MeshExtent.Y > KINDA_SMALL_NUMBER &&
            MeshExtent.Z > KINDA_SMALL_NUMBER)
        {
            FVector CylinderScale(
                CenterRadius / MeshExtent.X,
                CenterRadius / MeshExtent.Y,
                (CylinderHeight * 0.5f) / MeshExtent.Z
            );

            mCenterComponent->SetRelativeScale3D(CylinderScale);

            float CylinderZ = CylinderHeight * 0.5f;

            mCenterComponent->SetRelativeLocation(
                FVector(0.0, 0.0, CylinderZ)
            );
        }
    }
    else if (mCenterComponent)
    {
        mCenterComponent->SetStaticMesh(nullptr);
    }

    // Создаём ступени
    for (int32 i = 0; i < TotalSteps; i++)
    {
        FString StepName = FString::Printf(TEXT("Step_%d"), i);

        UStaticMeshComponent* Step =
            NewObject<UStaticMeshComponent>(this, *StepName);

        Step->SetStaticMesh(StepMesh);
        Step->SetupAttachment(RootComponent);

        float Angle = FMath::DegreesToRadians(AngleStep * i);

        float X = FMath::Cos(Angle) * Radius;
        float Y = FMath::Sin(Angle) * Radius;
        float Z = i * HeightBetweenStep;

        FVector StepLocation;

        if (bIsClockwise)
        {
            StepLocation = FVector(X, Y, Z);
        }
        else
        {
            StepLocation = FVector(Y, X, Z);
        }

        Step->SetRelativeLocation(StepLocation);

        FRotator StepRotation(0.0f, i * AngleStep, 0.0f);
        Step->SetRelativeRotation(StepRotation);

        Step->RegisterComponent();
        mStepComponents.Add(Step);
    }
}

void AUE13SpiralStairs::DestroyStairComponents()
{
	for (UStaticMeshComponent* lComp : mStepComponents)
	{
		if (lComp)
		{
			lComp->DestroyComponent();

		}

	}

	mStepComponents.Empty();

}

