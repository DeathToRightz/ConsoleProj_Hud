// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h" // Required for GEngine

#include "HealthComponent.h"

#include "Blueprint/UserWidget.h" // Required for CreateWidget
#include <Kismet/GameplayStatics.h>
//#include <Kismet/GameplayStatics.h>


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	Owner = GetOwner(); //Get our parent the actor/Player

	
	if (Owner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor connected"));

		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage); //Bind the take damage method to the player

		Health = MaxHealth;
	}

	if (!MyWidgetClass)
	{
		static ConstructorHelpers::FClassFinder<UUserWidget> WidgetBPClass(TEXT("/Game/Widgets/Widget_Lose"));
		if (WidgetBPClass.Succeeded())
		{
			UE_LOG(LogTemp, Warning, TEXT("Widget Found"));


			MyWidgetClass = WidgetBPClass.Class;

		}
	}

	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (MyWidgetClass && !MyWidgetInstance)
	{
		MyWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), MyWidgetClass);

		if (MyWidgetInstance)
		{
			UE_LOG(LogTemp, Warning, TEXT("Lose widget created successfully"));

		}
	}
	

	if (!PlayerController)
	{
		PlayerController = GetWorld()->GetFirstPlayerController();
	}
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigateBy, AActor* DamageCauser)
{
	//Handle taking damage

	
	
		Health -= Damage;
	
	

	Health = FMath::Clamp(Health, 0, MaxHealth);

	GEngine->AddOnScreenDebugMessage(
		-1,            
		5.0f,         
		FColor::Red,
		FString::Printf(TEXT("Current Health is: %f"), Health) 
	);

	

	if (Health == 0 && MyWidgetInstance && !MyWidgetInstance->IsInViewport())
	{
		UE_LOG(LogTemp, Warning, TEXT("Display Widget"));

		MyWidgetInstance->AddToViewport();

		if (PlayerController)
		{
			FInputModeUIOnly InputMode;
			PlayerController->SetInputMode(InputMode);
			PlayerController->bShowMouseCursor = true;
			UGameplayStatics::SetGamePaused(GetWorld(), true);
		}
	


		
	}
	
}

