##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Progetto
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale
ProjectPath            :=C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Progetto
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Beatrice
Date                   :=08/01/2023
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :="C:/Program Files/mingw64/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files/mingw64/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :="C:/Program Files/mingw64/bin/windres.exe"
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := "C:/Program Files/mingw64/bin/ar.exe" rcu
CXX      := "C:/Program Files/mingw64/bin/g++.exe"
CC       := "C:/Program Files/mingw64/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/mingw64/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/Battleship.cpp$(ObjectSuffix) $(IntermediateDirectory)/AttackGrid.cpp$(ObjectSuffix) $(IntermediateDirectory)/DefenceGrid.cpp$(ObjectSuffix) $(IntermediateDirectory)/Position.cpp$(ObjectSuffix) $(IntermediateDirectory)/Log.cpp$(ObjectSuffix) $(IntermediateDirectory)/replay.cpp$(ObjectSuffix) $(IntermediateDirectory)/Match.cpp$(ObjectSuffix) $(IntermediateDirectory)/Ship.cpp$(ObjectSuffix) $(IntermediateDirectory)/Grid.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Support.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Player.cpp$(ObjectSuffix): Player.cpp $(IntermediateDirectory)/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Player.cpp$(DependSuffix) -MM Player.cpp

$(IntermediateDirectory)/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Player.cpp$(PreprocessSuffix) Player.cpp

$(IntermediateDirectory)/Battleship.cpp$(ObjectSuffix): Battleship.cpp $(IntermediateDirectory)/Battleship.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Battleship.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Battleship.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Battleship.cpp$(DependSuffix): Battleship.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Battleship.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Battleship.cpp$(DependSuffix) -MM Battleship.cpp

$(IntermediateDirectory)/Battleship.cpp$(PreprocessSuffix): Battleship.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Battleship.cpp$(PreprocessSuffix) Battleship.cpp

$(IntermediateDirectory)/AttackGrid.cpp$(ObjectSuffix): AttackGrid.cpp $(IntermediateDirectory)/AttackGrid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/AttackGrid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AttackGrid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AttackGrid.cpp$(DependSuffix): AttackGrid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AttackGrid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AttackGrid.cpp$(DependSuffix) -MM AttackGrid.cpp

$(IntermediateDirectory)/AttackGrid.cpp$(PreprocessSuffix): AttackGrid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AttackGrid.cpp$(PreprocessSuffix) AttackGrid.cpp

$(IntermediateDirectory)/DefenceGrid.cpp$(ObjectSuffix): DefenceGrid.cpp $(IntermediateDirectory)/DefenceGrid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/DefenceGrid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DefenceGrid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DefenceGrid.cpp$(DependSuffix): DefenceGrid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DefenceGrid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DefenceGrid.cpp$(DependSuffix) -MM DefenceGrid.cpp

$(IntermediateDirectory)/DefenceGrid.cpp$(PreprocessSuffix): DefenceGrid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DefenceGrid.cpp$(PreprocessSuffix) DefenceGrid.cpp

$(IntermediateDirectory)/Position.cpp$(ObjectSuffix): Position.cpp $(IntermediateDirectory)/Position.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Position.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Position.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Position.cpp$(DependSuffix): Position.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Position.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Position.cpp$(DependSuffix) -MM Position.cpp

$(IntermediateDirectory)/Position.cpp$(PreprocessSuffix): Position.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Position.cpp$(PreprocessSuffix) Position.cpp

$(IntermediateDirectory)/Log.cpp$(ObjectSuffix): Log.cpp $(IntermediateDirectory)/Log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Log.cpp$(DependSuffix): Log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Log.cpp$(DependSuffix) -MM Log.cpp

$(IntermediateDirectory)/Log.cpp$(PreprocessSuffix): Log.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Log.cpp$(PreprocessSuffix) Log.cpp

$(IntermediateDirectory)/replay.cpp$(ObjectSuffix): replay.cpp $(IntermediateDirectory)/replay.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/replay.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/replay.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/replay.cpp$(DependSuffix): replay.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/replay.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/replay.cpp$(DependSuffix) -MM replay.cpp

$(IntermediateDirectory)/replay.cpp$(PreprocessSuffix): replay.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/replay.cpp$(PreprocessSuffix) replay.cpp

$(IntermediateDirectory)/Match.cpp$(ObjectSuffix): Match.cpp $(IntermediateDirectory)/Match.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Match.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Match.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Match.cpp$(DependSuffix): Match.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Match.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Match.cpp$(DependSuffix) -MM Match.cpp

$(IntermediateDirectory)/Match.cpp$(PreprocessSuffix): Match.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Match.cpp$(PreprocessSuffix) Match.cpp

$(IntermediateDirectory)/Ship.cpp$(ObjectSuffix): Ship.cpp $(IntermediateDirectory)/Ship.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Ship.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ship.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Ship.cpp$(DependSuffix): Ship.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Ship.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Ship.cpp$(DependSuffix) -MM Ship.cpp

$(IntermediateDirectory)/Ship.cpp$(PreprocessSuffix): Ship.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Ship.cpp$(PreprocessSuffix) Ship.cpp

$(IntermediateDirectory)/Grid.cpp$(ObjectSuffix): Grid.cpp $(IntermediateDirectory)/Grid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Grid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Grid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Grid.cpp$(DependSuffix): Grid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Grid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Grid.cpp$(DependSuffix) -MM Grid.cpp

$(IntermediateDirectory)/Grid.cpp$(PreprocessSuffix): Grid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Grid.cpp$(PreprocessSuffix) Grid.cpp

$(IntermediateDirectory)/Support.cpp$(ObjectSuffix): Support.cpp $(IntermediateDirectory)/Support.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Support.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Support.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Support.cpp$(DependSuffix): Support.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Support.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Support.cpp$(DependSuffix) -MM Support.cpp

$(IntermediateDirectory)/Support.cpp$(PreprocessSuffix): Support.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Support.cpp$(PreprocessSuffix) Support.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix): Submarine.cpp $(IntermediateDirectory)/Submarine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Beatrice/OneDrive/Desktop/ProgettoFinale/Progetto/Submarine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Submarine.cpp$(DependSuffix): Submarine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Submarine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Submarine.cpp$(DependSuffix) -MM Submarine.cpp

$(IntermediateDirectory)/Submarine.cpp$(PreprocessSuffix): Submarine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Submarine.cpp$(PreprocessSuffix) Submarine.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


