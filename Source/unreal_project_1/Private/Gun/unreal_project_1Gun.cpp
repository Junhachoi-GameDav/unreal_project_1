// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/unreal_project_1Gun.h"
#include "unreal_project_1Bullet.h"
#include <Kismet/KismetSystemLibrary.h>
#include <GamePlay/unreal_project_1Character.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
Aunreal_project_1Gun::Aunreal_project_1Gun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
//총알 속도 및 생성
void Aunreal_project_1Gun::FireBulletCPP(UClass* BulletClass, FTransform Transform)
{
	Aunreal_project_1Bullet* Bullet = Cast<Aunreal_project_1Bullet>(GetWorld()->SpawnActor(BulletClass, &Transform));
	if (Bullet) {
		Bullet->SetSpeedCPP(BulletSpeedCPP);
	}
}
//총 타이머
void Aunreal_project_1Gun::RegisterNextFireCPP(float Duration)
{
	TimerFireCPP = UKismetSystemLibrary::K2_SetTimer(this, TEXT("Fire"), Duration, false);
}

void Aunreal_project_1Gun::FireReleasedCPP()
{
	IsFirePressedCPP = false;
	GetWorld()->GetTimerManager().ClearTimer(TimerFireCPP);
}

bool Aunreal_project_1Gun::IsFiringCPP() const
{
	return IsFirePressedCPP && GetWorld()->GetTimerManager().IsTimerActive(TimerFireCPP);
}

void Aunreal_project_1Gun::MakeRecoilCPP()
{
	Aunreal_project_1Character* Character = Cast<Aunreal_project_1Character>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Character) {
		float Pitch = FMath::FRandRange(0, -0.2);
		Character->AddControllerPitchInput(Pitch);

		float Yaw = FMath::FRandRange(-0.15, 0.15);
		Character->AddControllerYawInput(Yaw);
	}
}

// Called when the game starts or when spawned
void Aunreal_project_1Gun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aunreal_project_1Gun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

