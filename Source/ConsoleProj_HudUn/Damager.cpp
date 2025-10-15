// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Damager.h"

// Sets default values
ADamager::ADamager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	BoxCollider->SetBoxExtent(FVector(30.f, 30.f, 30.f));
	BoxCollider->SetCollisionProfileName("BlockAllDynamic");
	RootComponent = BoxCollider;

	BoxCollider->OnComponentHit.AddDynamic(this, &ADamager::OnComponentHit);
}

// Called when the game starts or when spawned
void ADamager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADamager::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("We hit something"));

	

	UGameplayStatics::ApplyDamage(OtherActor, 1.f, GetWorld()->GetFirstPlayerController(), this, UDamageType::StaticClass());
	
	

}

