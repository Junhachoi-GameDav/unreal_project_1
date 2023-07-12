// Fill out your copyright notice in the Description page of Project Settings.

//�ٸ� ��⿡�� �����ö� <>
#include "GamePlay/unreal_project_1Character.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <Kismet/GameplayStatics.h>
#include <EnhancedInputComponent.h>

// Sets default values
Aunreal_project_1Character::Aunreal_project_1Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//if������ null������ ���� ��

	ShadowBodyCPP = CreateAbstractDefaultSubobject<USkeletalMeshComponent>(TEXT("ShadowBodyCPP"));
	if (ShadowBodyCPP)
	{
		ShadowBodyCPP->SetupAttachment(RootComponent);
		weapon_in_backCPP = CreateAbstractDefaultSubobject<UChildActorComponent>(TEXT("weapon_in_backCPP"));
		if (weapon_in_backCPP)
		{
			weapon_in_backCPP->SetupAttachment(ShadowBodyCPP);
		}
	}
	
	LowerBodyCPP = CreateAbstractDefaultSubobject<USkeletalMeshComponent>(TEXT("LowerBodyCPP"));
	LowerBodyCPP->SetupAttachment(RootComponent);

	CameraCPP = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("CameraCPP"));
	if (CameraCPP)
	{
		CameraCPP->SetupAttachment(RootComponent);
		first_personCPP = CreateAbstractDefaultSubobject<USkeletalMeshComponent>(TEXT("first_personCPP"));
		if (first_personCPP) 
		{
			first_personCPP->SetupAttachment(CameraCPP);
			weapon_in_handCPP = CreateAbstractDefaultSubobject<UChildActorComponent>(TEXT("weapon_in_handCPP"));
			if (weapon_in_handCPP)
			{
				weapon_in_handCPP->SetupAttachment(first_personCPP);
			}
		}
	}
}

float Aunreal_project_1Character::GetSpeedCPP() const
{
	return GetVelocity().Length();
}

bool Aunreal_project_1Character::CanRunCPP() const
{
	return (MoveForwardValueCPP > 0.0) && IsRunPressedCPP;
}

void Aunreal_project_1Character::TickRunCPP()
{
	if (CanRunCPP()) 
	{
		switch (StateCPP)
		{
		case StateOfCharacterCPP::Idle:
			StateCPP = StateOfCharacterCPP::Running;
			GetCharacterMovement()->MaxWalkSpeed *=2.0;
		}
	}
	else
	{
		switch (StateCPP)
		{
		case StateOfCharacterCPP::Running:
			StateCPP = StateOfCharacterCPP::Idle;
			GetCharacterMovement()->MaxWalkSpeed *= 0.5;
		}
		
	}
}

void Aunreal_project_1Character::OnFootstepLeftCPP()
{
	UGameplayStatics::PlaySoundAtLocation(this, FootstepLeftSoundCPP, LowerBodyCPP->GetSocketLocation("foot_l"));
}

// Called when the game starts or when spawned
void Aunreal_project_1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void Aunreal_project_1Character::OnTriggerRun(const FInputActionValue& Value)
{
	IsRunPressedCPP = Value.Get<bool>();
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
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(RunInputAction, ETriggerEvent::Triggered, this, &Aunreal_project_1Character::OnTriggerRun);
	}
}
