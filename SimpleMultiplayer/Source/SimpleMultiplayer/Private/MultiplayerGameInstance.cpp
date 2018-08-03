// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiplayerGameInstance.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

UMultiplayerGameInstance::UMultiplayerGameInstance(const FObjectInitializer & ObjectIn)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"))
}

void UMultiplayerGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"))
}

//To host a game from the lobby
void UMultiplayerGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!Engine) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));
	UWorld* World = GetWorld();
	if(!World) return;
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UMultiplayerGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!Engine) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!PlayerController) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
