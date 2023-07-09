// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/unreal_project_1Character.h"

// Sets default values
Aunreal_project_1Character::Aunreal_project_1Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShadowBodyCPP = CreateAbstractDefaultSubobject<USkeletalMeshComponent>(TEXT("ShadowBodyCPP"));
	ShadowBodyCPP->SetupAttachment(RootComponent);

	weapon_in_backCPP = CreateAbstractDefaultSubobject<UChildActorComponent>(TEXT("weapon_in_backCPP"));
	weapon_in_backCPP->SetupAttachment(ShadowBodyCPP);

	LowerBodyCPP = CreateAbstractDefaultSubobject<USkeletalMeshComponent>(TEXT("LowerBodyCPP"));
	LowerBodyCPP->SetupAttachment(RootComponent);

	CameraCPP = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("CameraCPP"));
	CameraCPP->SetupAttachment(RootComponent);

	first_personCPP = CreateAbstractDefaultSubobject<USkeletalMeshComponent>(TEXT("first_personCPP"));
	first_personCPP->SetupAttachment(CameraCPP);

	weapon_in_handCPP = CreateAbstractDefaultSubobject<UChildActorComponent>(TEXT("weapon_in_handCPP"));
	weapon_in_handCPP->SetupAttachment(first_personCPP);
}

// Called when the game starts or when spawned
void Aunreal_project_1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aunreal_project_1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Aunreal_project_1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

