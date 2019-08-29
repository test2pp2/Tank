// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Components/ArrowComponent.h"
#include "PaperSpriteComponent.h"
#include "Turret.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    if (RootComponent != nullptr) 
    {
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TankBase"));
    }

    TankDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("TankDirection"));
    if (!TankDirection->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform))
    {
        return;
    }

    TankSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TankSprite"));
    if (!TankSprite->AttachToComponent(TankDirection, FAttachmentTransformRules::KeepRelativeTransform))
    {
        return;
    }

    UCameraComponent* Cameracomponent = nullptr;

    ChildTurret = CreateDefaultSubobject<UChildActorComponent>(TEXT("Turret"));
    ChildTurret->AttachToComponent(TankDirection, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
