// Copyright Epic Games, Inc. All Rights Reserved.


#include "FireAxeProjectile.h"

FName EnemyTag = TEXT("Enemy");

// Sets default values
AFireAxeProjectile::AFireAxeProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AxeMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	AxeCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));

	RootComponent = AxeCapsule;

	AxeMesh->AttachToComponent(AxeCapsule, FAttachmentTransformRules::KeepRelativeTransform);


	AxeCapsule->OnComponentBeginOverlap.AddDynamic(this, &AFireAxeProjectile::OnOverlapBegin);
	AxeCapsule->OnComponentEndOverlap.AddDynamic(this, &AFireAxeProjectile::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AFireAxeProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("Fire Axe Begin"));
}

// Called every frame
void AFireAxeProjectile::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	const FVector AxeLocation = GetActorLocation();
	const FVector PositionChangeVector = MovementDirection * Speed * DeltaTime;
	SetActorLocation(AxeLocation + PositionChangeVector);
	
	FRotator AxeRotation = AxeMesh->GetRelativeRotation();
	AxeRotation.Roll += RotationSpeed * DeltaTime;
	AxeMesh->SetRelativeRotation(AxeRotation);
	
}

void AFireAxeProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap begin"));
	if (OtherActor->Tags.Contains(EnemyTag))
	{
		UE_LOG(LogTemp, Log, TEXT("Overlap with enemy begin"));
	}
	
}

void AFireAxeProjectile::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap end"));
}

