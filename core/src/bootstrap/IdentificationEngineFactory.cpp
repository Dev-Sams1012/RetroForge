#include "retroforge/bootstrap/IdentificationEngineFactory.hpp"

#include "retroforge/identification/detectors/CueSheetResolver.hpp"
#include "retroforge/identification/detectors/DreamcastCdiDetector.hpp"
#include "retroforge/identification/detectors/DreamcastGdiDetector.hpp"
#include "retroforge/identification/detectors/GameCubeDetector.hpp"
#include "retroforge/identification/detectors/PbpDetector.hpp"
#include "retroforge/identification/detectors/Ps1Detector.hpp"
#include "retroforge/identification/detectors/Ps2Detector.hpp"
#include "retroforge/identification/detectors/PspDetector.hpp"
#include "retroforge/identification/detectors/SegaCdDetector.hpp"
#include "retroforge/identification/detectors/SegaSaturnDetector.hpp"

#include <memory>

namespace retroforge::bootstrap {

identification::ConsoleIdentifier IdentificationEngineFactory::criar() {
    identification::ConsoleIdentifier motor;

    motor.register_container_detector(
        std::make_unique<identification::detectors::DreamcastCdiDetector>());
    motor.register_container_detector(
        std::make_unique<identification::detectors::DreamcastGdiDetector>());

    motor.register_container_resolver(
        std::make_unique<identification::detectors::CueSheetResolver>());

    motor.register_detector(std::make_unique<identification::detectors::GameCubeDetector>());
    motor.register_detector(std::make_unique<identification::detectors::PbpDetector>());
    motor.register_detector(std::make_unique<identification::detectors::Ps1Detector>());
    motor.register_detector(std::make_unique<identification::detectors::Ps2Detector>());
    motor.register_detector(std::make_unique<identification::detectors::PspDetector>());
    motor.register_detector(std::make_unique<identification::detectors::SegaCdDetector>());
    motor.register_detector(std::make_unique<identification::detectors::SegaSaturnDetector>());

    return motor;
}

} // namespace retroforge::bootstrap