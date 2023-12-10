#include "Windowing.h"
#include "imgui.h"
#include "imfilebrowser.h"
#include "MainMenu.h"
#include "Extras.h"
#include <cstring> // for strerror
#include <cstdlib> // for _getcwd (Windows) or getcwd (Unix-like)
#include <unistd.h>

void editprefwindow(ImGui::FileBrowser fileDialog){
    // Buffer to hold the current working directory
    //ImGui::SetNextWindowPos(ImVec2(window_width / 2.0, (window_height / 4.0)));
    ImGui::Begin("Preferences", &editpref);
    ImGui::Text("%s", appsettings["defaultfolder"].c_str());
    /*if(ImGui::Button("Choose font")){
        fileDialog.Open();
        fileDialog.Display();
    }*/
    static int currentItem = 0;
    if (ImGui::TreeNode("Fonts"))
    {
        ImGui::Text("Font name");
        if (ImGui::BeginCombo("##combo", fontlist[currentItem].c_str())) {
            for (int i = 0; i < fontlist.size(); i++) {
                const bool isSelected = (currentItem == i);
                if (ImGui::Selectable(fontlist[i].c_str(), isSelected))
                    currentItem = i;
                if (isSelected)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }
        ImGui::TreePop();
    }
    //ImGui::Button("Save");
}
