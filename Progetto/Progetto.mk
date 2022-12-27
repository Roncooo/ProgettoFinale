##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Progetto
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/franc/Desktop/ProgettoFinale
ProjectPath            :=C:/Users/franc/Desktop/ProgettoFinale/Progetto
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Progetto
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Francesco
Date                   :=27/12/2022
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/bin/g++.exe -shared -fPIC
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
OutputDirectory        :=C:/Users/franc/Desktop/ProgettoFinale/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/bin/windres.exe
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
AR       := C:/mingw64/bin/ar.exe rcu
CXX      := C:/mingw64/bin/g++.exe
CC       := C:/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Griglia.cpp$(ObjectSuffix) $(IntermediateDirectory)/Nave.cpp$(ObjectSuffix) $(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sottomarino.cpp$(ObjectSuffix) $(IntermediateDirectory)/Supporto.cpp$(ObjectSuffix) $(IntermediateDirectory)/GrigliaAttacco.cpp$(ObjectSuffix) $(IntermediateDirectory)/Corazzata.cpp$(ObjectSuffix) $(IntermediateDirectory)/Posizione.cpp$(ObjectSuffix) $(IntermediateDirectory)/GrigliaDifesa.cpp$(ObjectSuffix) \
	



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Griglia.cpp$(ObjectSuffix): Griglia.cpp $(IntermediateDirectory)/Griglia.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/Griglia.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Griglia.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Griglia.cpp$(DependSuffix): Griglia.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Griglia.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Griglia.cpp$(DependSuffix) -MM Griglia.cpp

$(IntermediateDirectory)/Griglia.cpp$(PreprocessSuffix): Griglia.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Griglia.cpp$(PreprocessSuffix) Griglia.cpp

$(IntermediateDirectory)/Nave.cpp$(ObjectSuffix): Nave.cpp $(IntermediateDirectory)/Nave.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/Nave.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Nave.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Nave.cpp$(DependSuffix): Nave.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Nave.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Nave.cpp$(DependSuffix) -MM Nave.cpp

$(IntermediateDirectory)/Nave.cpp$(PreprocessSuffix): Nave.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Nave.cpp$(PreprocessSuffix) Nave.cpp

$(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix): Giocatore.cpp $(IntermediateDirectory)/Giocatore.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/Giocatore.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Giocatore.cpp$(DependSuffix): Giocatore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Giocatore.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Giocatore.cpp$(DependSuffix) -MM Giocatore.cpp

$(IntermediateDirectory)/Giocatore.cpp$(PreprocessSuffix): Giocatore.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Giocatore.cpp$(PreprocessSuffix) Giocatore.cpp

$(IntermediateDirectory)/Sottomarino.cpp$(ObjectSuffix): Sottomarino.cpp $(IntermediateDirectory)/Sottomarino.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/Sottomarino.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sottomarino.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sottomarino.cpp$(DependSuffix): Sottomarino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sottomarino.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sottomarino.cpp$(DependSuffix) -MM Sottomarino.cpp

$(IntermediateDirectory)/Sottomarino.cpp$(PreprocessSuffix): Sottomarino.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sottomarino.cpp$(PreprocessSuffix) Sottomarino.cpp

$(IntermediateDirectory)/Supporto.cpp$(ObjectSuffix): Supporto.cpp $(IntermediateDirectory)/Supporto.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/Supporto.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Supporto.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Supporto.cpp$(DependSuffix): Supporto.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Supporto.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Supporto.cpp$(DependSuffix) -MM Supporto.cpp

$(IntermediateDirectory)/Supporto.cpp$(PreprocessSuffix): Supporto.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Supporto.cpp$(PreprocessSuffix) Supporto.cpp

$(IntermediateDirectory)/GrigliaAttacco.cpp$(ObjectSuffix): GrigliaAttacco.cpp $(IntermediateDirectory)/GrigliaAttacco.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/GrigliaAttacco.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GrigliaAttacco.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GrigliaAttacco.cpp$(DependSuffix): GrigliaAttacco.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GrigliaAttacco.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GrigliaAttacco.cpp$(DependSuffix) -MM GrigliaAttacco.cpp

$(IntermediateDirectory)/GrigliaAttacco.cpp$(PreprocessSuffix): GrigliaAttacco.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GrigliaAttacco.cpp$(PreprocessSuffix) GrigliaAttacco.cpp

$(IntermediateDirectory)/Corazzata.cpp$(ObjectSuffix): Corazzata.cpp $(IntermediateDirectory)/Corazzata.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/Corazzata.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Corazzata.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Corazzata.cpp$(DependSuffix): Corazzata.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Corazzata.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Corazzata.cpp$(DependSuffix) -MM Corazzata.cpp

$(IntermediateDirectory)/Corazzata.cpp$(PreprocessSuffix): Corazzata.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Corazzata.cpp$(PreprocessSuffix) Corazzata.cpp

$(IntermediateDirectory)/Posizione.cpp$(ObjectSuffix): Posizione.cpp $(IntermediateDirectory)/Posizione.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/Posizione.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Posizione.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Posizione.cpp$(DependSuffix): Posizione.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Posizione.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Posizione.cpp$(DependSuffix) -MM Posizione.cpp

$(IntermediateDirectory)/Posizione.cpp$(PreprocessSuffix): Posizione.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Posizione.cpp$(PreprocessSuffix) Posizione.cpp

$(IntermediateDirectory)/GrigliaDifesa.cpp$(ObjectSuffix): GrigliaDifesa.cpp $(IntermediateDirectory)/GrigliaDifesa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/franc/Desktop/ProgettoFinale/Progetto/GrigliaDifesa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GrigliaDifesa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GrigliaDifesa.cpp$(DependSuffix): GrigliaDifesa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GrigliaDifesa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GrigliaDifesa.cpp$(DependSuffix) -MM GrigliaDifesa.cpp

$(IntermediateDirectory)/GrigliaDifesa.cpp$(PreprocessSuffix): GrigliaDifesa.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GrigliaDifesa.cpp$(PreprocessSuffix) GrigliaDifesa.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


