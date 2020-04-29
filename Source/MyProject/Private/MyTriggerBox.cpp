// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "Components/BoxComponent.h"
#include "CarPawn.h"

// Sets default values
AMyTriggerBox::AMyTriggerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);

	

}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AMyTriggerBox::OnEndOverlap);
}

// Called every frame
void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyTriggerBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACarPawn* carPawn = CastChecked<ACarPawn>(OtherActor);
	if (carPawn != nullptr)
	{
		currentCars++;
		if (currentCars >= totalCarsToWin) {
			UE_LOG(LogTemp, Warning, TEXT("Has ganado!"));
		}
	}
}
	void AMyTriggerBox::OnEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
	{
		ACarPawn* carPawn = CastChecked<ACarPawn>(OtherActor);
		if (carPawn != nullptr)
		{
			currentCars--;
		}
	}
