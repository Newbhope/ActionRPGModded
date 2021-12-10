// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireAxeProjectile.generated.h"

UCLASS()
class ACTIONRPG_API AFireAxeProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireAxeProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* AxeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* AxeCapsule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeed = 60;

public:
	FVector MovementDirection = FVector::ZeroVector;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
