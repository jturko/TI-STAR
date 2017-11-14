//thanks to dhymers

#include "HadronicStackingAction.hh"
#include "G4ParticleTable.hh"
#include "G4VProcess.hh"

HadronicStackingAction::HadronicStackingAction()
{
	particleTable = G4ParticleTable::GetParticleTable();
	
	//deuteronDef = nullptr;
	//protonDef = nullptr;
	alphaDef = nullptr;
	electronDef = nullptr;

   
}

HadronicStackingAction::~HadronicStackingAction()
{

outfile.close();

}

G4ClassificationOfNewTrack HadronicStackingAction::ClassifyNewTrack(const G4Track* track){
G4ClassificationOfNewTrack classification;
    
    //if (deuteronDef == nullptr){
    if (protonDef == nullptr){
    //if (alphaDef == nullptr){
		//deuteronDef = particleTable->FindParticle("deuteron");
		protonDef = particleTable->FindParticle("proton");
		//alphaDef = particleTable->FindParticle("alpha");
                 
	}
    if (electronDef == nullptr){
	electronDef = particleTable->FindParticle("e-");
    }
    
    classification = fUrgent;
    
  
    //if(track->GetParticleDefinition() == deuteronDef){
	if(track->GetParticleDefinition() == protonDef){
	//if(track->GetParticleDefinition() == alphaDef){
       
  
   const G4String* processname = &(track->GetCreatorProcess()->GetProcessName());
   //G4cout << "Process Name :  "<<processname<<G4endl;
   
    const G4ThreeVector& position = track->GetPosition() / CLHEP::mm;
    //fPosition.SetXYZ(position.getX(),position.getY(),position.getZ());

    //if(track->GetParentID() == 1 && processname->compareTo("ScreenedElastic") == 0)// for beamin
    //if(track->GetParentID() == 0) // for rutherford
  

    }
else if(track->GetParticleDefinition() == electronDef){
 classification = fKill;
}
    return classification;
}

void HadronicStackingAction::NewStage()
{}

void HadronicStackingAction::PrepareNewEvent()
{}
