// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h" // Required for GEngine

#include "HealthComponent.h"

#include "Blueprint/UserWidget.h" // Required for CreateWidget


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

	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetBPClass(TEXT("/Game/Widgets/Widget_Lose"));

	if (WidgetBPClass.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget Found"));

		
		MyWidgetClass = WidgetBPClass.Class;
		
		//VictoryWidgetClass = WidgetBPClass.Class;
	}

}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
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

	//Displays Widget when Health is 0
	if (Health == 0)
	{
		
	}
}

