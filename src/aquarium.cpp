#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <random>


#include <google/protobuf/util/json_util.h>
#include "poisson.h"
#include "aquarium.h"
#include "aquarium.pb.h"

//----------------------------------------------------------------//

Aquarium::Aquarium(const std::vector<double>  pDim, std::vector<std::shared_ptr<Poisson>>pPoissons, std::vector<int> const pSizes)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    mPoissons = pPoissons; 
    mDim[0] = pDim[0];
    mDim[1] = pDim[1];
    mDim[2] = pDim[2];
    mDim[3] = pDim[3];
    addAlgues(pSizes);
}

//----------------------------------------------------------------//

void Aquarium::addAlgue(int pSize)
{
    std::shared_ptr<Algue> lAlgue = std::make_shared<Algue> (pSize,mIdAlgue);
    mAlgues.push_back(lAlgue);
    ++mIdAlgue; 
}

//----------------------------------------------------------------//

void Aquarium::addAlgues(std::vector<int> const pSizes)
{
    for 
        (unsigned int lI = 0; lI < pSizes.size(); ++lI)
    {
        std::shared_ptr<Algue> lAlgueTemp = std::make_shared<Algue> (pSizes[lI],mIdAlgue);
        mAlgues.push_back(lAlgueTemp);
        ++mIdAlgue; 
    }
}

//----------------------------------------------------------------//

//----------------------------------------------------------------//

void Aquarium::addPoisson(std::shared_ptr<Poisson> pPoisson)
{
    mPoissons.push_back(pPoisson); 
}

//----------------------------------------------------------------//

void Aquarium::printInfo()
{
    std::cout<<"----------- "<< mPoch << " ------------"<<std::endl;
    std::cout<<"Nombres d'algues : "<<mAlgues.size()<<std::endl;
    std::cout<<"Listes des poissons : "<<std::endl;
    for 
        (unsigned int lI = 0; lI < mPoissons.size(); ++lI)
    {
        mPoissons[lI]->sayHello();
    }
} 

//----------------------------------------------------------------//
template <typename T>
void Aquarium::deleteDead(std::vector<T>& pVector, std::vector<int> pDead)
{
    std::sort(pDead.begin(), pDead.end());
    for (int lI : pDead) 
    {
        if (lI < pVector.size())
            pVector.erase(pVector.begin() + lI);
    }
}

//----------------------------------------------------------------//

void Aquarium::endTour()
{
    std::vector<int> lDeadFish;  
    std::vector<int> lDeadAlgues;  
    int lI = 0;
    int lJ = 0; 
    for 
        (auto &p : mPoissons)
    {
        if (p->isLive())
        {
            if (!(p->getHasEat()))
            {
                p->dontEat();
            }
        }
        if (!p->isLive())
        {
            lDeadFish.push_back(lI);
        }
        p->initEat();
        ++lI; 
    }
    for 
        (auto &a : mAlgues)
    {
        if 
            (a->isDead()) {lDeadAlgues.push_back(lJ);}
            ++lJ;
    }
    deleteDead(mPoissons, lDeadFish); 
    deleteDead(mAlgues, lDeadAlgues);
    updatesPos();
}

//----------------------------------------------------------------//

void Aquarium::PassTour()
{
    std::random_device rd;           
    for 
        (auto& p : mPoissons)
    {
        
        if (p->isLive())
             
             
            switch (p->getType())
            {
                case TypePoisson::HERBIVORE:
                {
                    if 
                        (!mAlgues.empty())
                    {        
                        std::mt19937 gen(rd());
                        std::uniform_int_distribution<> distrib(0, (mAlgues.size()-1));
                        int lRandomNumber = distrib(gen);
                        if (!mAlgues[lRandomNumber]->isDead())
                        {
                            mAlgues[lRandomNumber]->beEat();
                            p->setEat();
                        }
                    }
                }
                case TypePoisson::CARNIVORE:
                {      
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> distrib(0, (mPoissons.size()-1)*10);
                    int lRandomNumber = distrib(gen);
                    if (lRandomNumber < mPoissons.size())
                    {
                        if 
                            (mPoissons[lRandomNumber]->getType() == TypePoisson::HERBIVORE)
                        {
                            mPoissons[lRandomNumber]->beAttack();
                            p->setEat();
                        }
                    }
                }
                    
                
            }      
    }
    endTour();

    ++mPoch;
}

//----------------------------------------------------------------//

void Aquarium::updatesPos()
{
    for (auto& p : mPoissons)
    {
        p->nextPos();
    }
}

//----------------------------------------------------------------//

std::string Aquarium::aquariumTojson()
{
    std::string lJson; 
    google::protobuf::util::JsonPrintOptions l0ptions;
    //l0ptions.add_whitespace = true; // Pretty-print the JSON
    //l0ptions.always_print_primitive_fields = true;
    aquarium_proto::Aquarium lAquaProto; 
    lAquaProto.set_tour(mPoch);
    for 
        (unsigned int lI = 0; lI < mPoissons.size(); ++lI)
    {
        aquarium_proto::Poisson *lPoissonTemp = lAquaProto.add_poissons();
        aquarium_proto::Pos* lPosProto = lPoissonTemp->mutable_pos();
        Pos lPos = mPoissons[lI]->getPos(); 
        lPosProto->set_x(lPos.x);
        lPosProto->set_y(lPos.y);
        lPosProto->set_vx(lPos.vx);
        lPosProto->set_vy(lPos.vy);
        lPoissonTemp->set_name(mPoissons[lI]->getName());
        lPoissonTemp->set_life(mPoissons[lI]->getLife()); 
        lPoissonTemp->set_islive(mPoissons[lI]->getLife() > 0);
        switch 
            (mPoissons[lI]->getType())
        {
            case TypePoisson::CARNIVORE :
            lPoissonTemp->set_type(aquarium_proto::Poisson::CARNIVORE);
            break;

            case TypePoisson::HERBIVORE :
            lPoissonTemp->set_type(aquarium_proto::Poisson::HERBIVORE);
            break;

            default:
            lPoissonTemp->set_type(aquarium_proto::Poisson::NORMAL);
            break;
        } 
    }
    for 
        (unsigned int lI = 0; lI < mAlgues.size(); ++lI)
    {
        aquarium_proto::Algue *lAlgueTemp = lAquaProto.add_algues();
        lAlgueTemp->set_id(mAlgues[lI]->getId()); 
        lAlgueTemp->set_size(mAlgues[lI]->getSize());
    }
    auto status = google::protobuf::util::MessageToJsonString(lAquaProto, &lJson); 
    std::cout<<lJson<<std::endl;
    return "";
}