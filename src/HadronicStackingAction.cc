//thanks dhymers

#include "HadronicStackingAction.hh"
#include "G4ParticleTable.hh"
#include "G4VProcess.hh"

HadronicStackingAction::HadronicStackingAction()
{
	particleTable = G4ParticleTable::GetParticleTable();
	
	deuteronDef = nullptr;
	//protonDef = nullptr;
	electronDef = nullptr;

    outfile.open("leila_deuteron_132Sn_beam_792MeV_gas_traprob1_1000mb.dat", std::ofstream::app | std::ofstream::out);
    outfile.open("deuteron_1beamIn.dat", std::ofstream::app | std::ofstream::out);
}

HadronicStackingAction::~HadronicStackingAction()
{

outfile.close();

}

G4ClassificationOfNewTrack HadronicStackingAction::ClassifyNewTrack(const G4Track* track){
G4ClassificationOfNewTrack classification;
    
    if (deuteronDef == nullptr){
    //if (protonDef == nullptr){
		deuteronDef = particleTable->FindParticle("deuteron");
		//protonDef = particleTable->FindParticle("proton");
                 
	}
    if (electronDef == nullptr){
	electronDef = particleTable->FindParticle("e-");
    }
    
    classification = fUrgent;
    
    //do not simulate electrons, to speed up simulation
    if(track->GetParticleDefinition() == deuteronDef){
	//if(track->GetParticleDefinition() == protonDef){
       
   //G4cout << "################################ Tracking of deuterons/protons ################################" << G4endl;
 
   //G4VProcess* creatorProcess = track-­>GetCreatorProcess();

   // char pName[1024];
   // strcpy(pName, track->GetCreatorProcess()->GetProcessName().c_str());
   const G4String* processname = &(track->GetCreatorProcess()->GetProcessName());
   //G4cout << "Process Name :  "<<processname<<G4endl;
   
    const G4ThreeVector& position = track->GetPosition() / CLHEP::mm;
    //fPosition.SetXYZ(position.getX(),position.getY(),position.getZ());

    if(track->GetParentID() == 1 && processname->compareTo("ScreenedElastic") == 0)// for beamin
    //if(track->GetParentID() == 0) // for rutherford
    //if(track->GetParentID() == 0) // for angular distribution

    //   G4cout << " *** Parent ID "<< track->GetParentID() << " *** track ID: " << track->GetTrackID() << " *** particle name: " << track->GetDefinition()->GetParticleName() << " *** process: " << processname << " *** kinetic energy (keV)= " << track->GetKineticEnergy()/CLHEP::keV << " *** total energy (GeV)= " << track->GetTotalEnergy()/CLHEP::GeV<< " *** Momentum (MeV/c2)?: " <<track->GetMomentum().mag() << " *** Theta (radian) : " << track->GetMomentumDirection().theta()/CLHEP::deg << " *** x: "<< position.getX() << " *** y: " << position.getY() << " *** z: "<< position.getZ() << G4endl;// GetMomentum().mag2()

     outfile << track->GetMomentumDirection().theta() / CLHEP::deg << " " << track->GetKineticEnergy() / CLHEP::keV << " " << track->GetTotalEnergy() / CLHEP::keV << " " << position.getX() / CLHEP::mm << " " << position.getY() / CLHEP::mm << " " <<position.getZ() / CLHEP::mm <<std::endl;

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

//G4ThreeVector  momentumC =  aStep->GetPreStepPoint()->GetMomentumDirection();
//G4double TheAlpha = momentumC.theta();
//G4double stepl = aStep->GetStepLength();
