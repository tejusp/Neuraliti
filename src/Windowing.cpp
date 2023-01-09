#include <cstring> // for strerror
#include <cstdlib> // for _getcwd (Windows) or getcwd (Unix-like)
#include <unistd.h>
#include <fstream>
#include "Windowing.h"
#include "imgui.h"
#include "imfilebrowser.h"
#include "MainMenu.h"
#include "Extras.h"
#include "picojson.h"

void editprefwindow(ImGui::FileBrowser fileDialog){
    // Buffer to hold the current working directory
    //ImGui::SetNextWindowPos(ImVec2(window_width / 2.0, (window_height / 4.0)));
    ImGui::Begin("Preferences", &editpref);
    
    /*if(ImGui::Button("Choose font")){
        fileDialog.Open();
        fileDialog.Display();
    }*/
    if (ImGui::TreeNode("Defaults"))
    {
        ImGui::Text("%s", "prefs.json [compiled]");
        ImGui::Text("%s", appsettings["defaultfolder"].c_str());
        ImGui::Text("%s", (appsettings["defaultfont"] + ", " + appsettings["fontsize"] ).c_str());
        ImGui::TreePop();
    }
    ImGui::Separator();
    static int currentItem = 0;
    static int currentSize = 3;
    if (ImGui::TreeNode("Fonts"))
    {
        ImGui::Text("Font name");
        if (ImGui::BeginCombo("##combo", fontlist[currentItem].c_str())) {
            for (int i = 0; i < fontlist.size(); i++) {
                const bool isSelected = (currentItem == i);
                if (ImGui::Selectable(fontlist[i].c_str(), isSelected))
                    currentItem = i;
                    appsettings["defaultfont"] = fontlist[currentItem];
                if (isSelected)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }
        //ImGui::SameLine();
        
        if (ImGui::BeginCombo("##combo2", fontsizelist[currentSize].c_str())) {
            for (int j = 0; j < fontsizelist.size(); j++) {
                const bool isSelected = (currentSize == j);
                if (ImGui::Selectable(fontsizelist[j].c_str(), isSelected))
                    currentSize = j;
                    appsettings["fontsize"] = fontsizelist[currentSize];
                if (isSelected)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }
        ImGui::TreePop();
        
    }
    if(ImGui::Button("Save")){
        // write to json
        // Write the updated JSON data back to the file
        overwriteLine("../prefs.json", 8, "\"fontsize\": \"" + appsettings["fontsize"] + "\"");
        addlogs("\nPreferences saved. Restart the app to see changes\n");
    }
}
