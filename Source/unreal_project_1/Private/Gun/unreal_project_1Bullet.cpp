// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/unreal_project_1Bullet.h"

// Sets default values
Aunreal_project_1Bullet::Aunreal_project_1Bullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletCPP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletCPP"));
	if (BulletCPP)
	{
		RootComponent = BulletCPP;
	}
}

void Aunreal_project_1Bullet::SetSpeedCPP(float Value)
{
	SpeedCPP = Value;
}

// Called when the game starts or when spawned
void Aunreal_project_1Bullet::BeginPlay()
{
	Super::BeginPlay();
	
	if (BulletCPP) {
		BulletCPP->OnComponentHit.AddUniqueDynamic(this, &Aunreal_project_1Bullet::OnHitCallback);
	}
}

void Aunreal_project_1Bullet::OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

// Called every frame
void Aunreal_project_1Bullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

