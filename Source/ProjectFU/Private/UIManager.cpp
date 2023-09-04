// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

UUIManager* UUIManager::getInstance()
{
	if (instance == nullptr) {
		instance = NewObject<UUIManager>();
	}
	return instance;
}
