// Fill out your copyright notice in the Description page of Project Settings.


#include "CarPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "Components/InputComponent.h"

// Sets default values
ACarPawn::ACarPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SprintArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("UCameraComp"));
	UFloatingPawnMovementComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovementComp"));


	StaticMeshComp->SetupAttachment(RootComponent);
	SprintArmComp->SetupAttachment(StaticMeshComp);
	CameraComp->SetupAttachment(SprintArmComp);

	SprintArmComp->bUsePawnControlRotation = true;
	SprintArmComp->SocketOffset = FVector(0, 0, 200);

}

// Called when the game starts or when spawned
void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent && "Can't found PlayerInputComponent");

	PlayerInputComponent->BindAction("Mensaje", EInputEvent::IE_Pressed, this, &ACarPawn::OnSpaceInput);
	PlayerInputComponent->BindAxis("MoverVertical", this, &ACarPawn::OnMoveVertical);
	PlayerInputComponent->BindAxis("MoverHorizontal", this, &ACarPawn::OnMoveHorizontal);

	PlayerInputComponent->BindAxis("MouseVertical", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MouseHorizontal", this, &APawn::AddControllerPitchInput);
}
void ACarPawn::OnSpaceInput()
{
	UE_LOG(LogTemp, Warning, TEXT("OnSpaceInput()"));
}

void ACarPawn::OnMoveVertical(float axis)
{
	UE_LOG(LogTemp, Warning, TEXT("Axis: %f"), axis);

	FVector v = GetActorForwardVector();
	AddMovementInput(v, axis);
}
void ACarPawn::OnMoveHorizontal(float axis)
{
	UE_LOG(LogTemp, Warning, TEXT("Axis: %f"), axis);

	FVector v = GetActorRightVector();
	AddMovementInput(v, axis);
}
