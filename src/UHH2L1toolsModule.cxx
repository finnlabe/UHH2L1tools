#include <iostream>
#include <memory>

#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Event.h"

using namespace std;
using namespace uhh2;

  /** \brief UHH module to prepare conversion to DF for L1 triggers
   *
   */
  class UHH2L1toolsModule: public AnalysisModule {
  public:

    explicit UHH2L1toolsModule(Context & ctx);
    virtual bool process(Event & event) override;

  private:

    // handle object
    uhh2::Event::Handle<double> h_evt_weight;

  };


  UHH2L1toolsModule::UHH2L1toolsModule(Context & ctx){

    std::cout << "Preparing run..."  << std::endl;

    // defining the handle that will store the event weights
    h_evt_weight = ctx.declare_event_output<double>("evt_weight");

    std::cout << "end prepare run..."  << std::endl;


  }


  bool UHH2L1toolsModule::process(Event & event) {

    // outputting the weight to the AnalysisTree
    event.set(h_evt_weight, event.weight);

    return true;
  }

UHH2_REGISTER_ANALYSIS_MODULE(UHH2L1toolsModule)
