#include "Windowing.h"
#include "imgui.h"
#include "imfilebrowser.h"
#include "MainMenu.h"

void editprefwindow(ImGui::FileBrowser fileDialog){
    //ImGui::SetNextWindowPos(ImVec2(window_width / 2.0, (window_height / 4.0)));
    ImGui::Begin("Preferences", &editpref);
    if(ImGui::Button("Choose font"))
        fileDialog.Open();
        fileDialog.Display();
}
