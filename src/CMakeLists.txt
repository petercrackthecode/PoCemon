cmake_minimum_required(VERSION 3.0.0)


add_executable (PoCemon "main.cpp" "PoCemon.cpp" "PoCemon.h" "PoCemonData.cpp" "PoCemonData.h" "Enums.h" "testTay.cpp" "testAman.cpp" "testPeter.cpp" "testKate.cpp" "Ability.cpp" "Ability.h" "AttackAbility.cpp" "AttackAbility.h" "randomGenerator.cpp" "randomGenerator.h" "Player.h" "Player.cpp" "AbilityFactory.h" "AbilityFactory.cpp" "Game.h" "Game.cpp" "GameSprite.h" "GameSprite.cpp" "Structs.h" "Battle.h" "Battle.cpp" "sfTeamListItem.h" "sfTeamListItem.cpp" "GameStateBattle.h" "GameStateBattle.cpp" "GameStateMenu.h" "GameStateMenu.cpp" "AssetManager.h" "AssetManager.cpp" "sfWidget.h" "sfWidget.cpp" "sfMenuContainer.h" "sfMenuContainer.cpp" "sfAction.h" "sfAction.cpp" "sfActionTarget.h" "sfActionTarget.cpp" "sfActionMap.h" "sfActionMap.cpp" "sfLabel.h" "sfLabel.cpp" "sfContainer.h" "sfContainer.cpp" "sfLayout.h" "sfLayout.cpp" "sfVLayout.h" "sfVLayout.cpp" "sfAbilityListItem.h" "sfAbilityListItem.cpp" "sfBattleScreen.h" "sfBattleScreen.cpp")
target_link_libraries(PoCemon sfml-graphics)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E copy_directory
				   ${CMAKE_SOURCE_DIR}/graphics $<TARGET_FILE_DIR:${PROJECT_NAME}>/graphics)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E copy_directory
				   ${CMAKE_SOURCE_DIR}/sounds $<TARGET_FILE_DIR:${PROJECT_NAME}>/sounds)