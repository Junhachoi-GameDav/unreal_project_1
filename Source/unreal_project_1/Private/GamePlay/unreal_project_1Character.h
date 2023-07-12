// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <InputAction.h>
#include "unreal_project_1Character.generated.h"

UENUM(BlueprintType)
enum class StateOfCharacterCPP : uint8
{
	Idle,
	Aiming,
	Reloading,
	Swapping,
	Running,
};

UCLASS()
class Aunreal_project_1Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Aunreal_project_1Character();

	//const 가 붙으면 불값등을 수정할수 없다. and pure가 자동으로 된다. 
	//const가 없으면 bluepinrtpure를 넣어줘야한다.(pure를 사용하고 싶을시)
	UFUNCTION(BlueprintCallable)
		virtual float GetSpeedCPP() const;
	UFUNCTION(BlueprintCallable)
		virtual bool CanRunCPP() const;

	UFUNCTION(BlueprintCallable)
		virtual void TickRunCPP();

	UFUNCTION(BlueprintCallable)
		virtual void OnFootstepLeftCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnTriggerRun(const FInputActionValue& Value);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		StateOfCharacterCPP StateCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		bool IsRunPressedCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
		float MoveForwardValueCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
		TObjectPtr<USoundBase> FootstepLeftSoundCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
		TObjectPtr<UInputAction> RunInputAction;

private:
	//uproperty 에디터에서 어떻게 보여줄것인가
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<USkeletalMeshComponent> ShadowBodyCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UChildActorComponent> weapon_in_backCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<USkeletalMeshComponent> LowerBodyCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UCameraComponent> CameraCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<USkeletalMeshComponent> first_personCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UChildActorComponent> weapon_in_handCPP;

};
