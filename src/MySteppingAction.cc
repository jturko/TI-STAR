
#include "MySteppingAction.hh"
#include "TRexRunAction.hh"
#include "TRexDetectorConstruction.hh"
#include "TRexPrimaryGeneratorAction.hh"

#include "G4SteppingManager.hh"
#include "G4VTouchable.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

// RunAction, DetectorConstruction, PrimaryGeneratorAction objets in argument
//MySteppingAction::MySteppingAction(TRexRunAction* run,TRexDetectorConstruction* det,TRexPrimaryGeneratorAction* pri) ***
//:Run(run),Detector(det),Primary(pri)***

MySteppingAction::MySteppingAction()
{ 
	

	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

MySteppingAction::~MySteppingAction()
{
	
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

//void MySteppingAction::UserSteppingAction(const G4Step* s)
void MySteppingAction::UserSteppingAction(const G4Step* s)
  
{ 



	
	
}
