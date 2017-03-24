/*
	bbstream
	Copyright (C) 2017  Emil Hummel Clausen

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program(LICENSE in root directory).  If not, see <http://www.gnu.org/licenses/>.

	Email: emil@hummel.yt
*/

#include <tinyxml2.h>
#include <string>
#include <vector>

namespace bbstream { namespace core { namespace protocols {
	enum AdaptationSetType {
		AUDIO,
		VIDEO
	};

	class Representation {
	public:
		std::string id;
		std::string bandwidth;
		std::string width;
		std::string height;
		std::string codecs;
		std::string scanType;
		std::string frameRate;

		Representation(const tinyxml2::XMLElement * payload, AdaptationSetType setType) {
			switch (setType)
			{
			case bbstream::core::protocols::AUDIO:
				id = payload->Attribute("id");
				bandwidth = payload->Attribute("bandwidth");
				break;
			case bbstream::core::protocols::VIDEO:
				id = payload->Attribute("id");
				bandwidth = payload->Attribute("bandwidth");
				width = payload->Attribute("width");
				height = payload->Attribute("height");
				codecs = payload->Attribute("codecs");
				scanType = payload->Attribute("scanType");
				frameRate = payload->Attribute("frameRate");
				break;
			default:
				break;
			}
		}
	};

	class SegmentTemplate {
	public:
		std::string timescale;
		std::string initialization;
		std::string media;
		std::string startNumber;
		std::string duration;

		SegmentTemplate(const tinyxml2::XMLElement * payload) {
			timescale = payload->Attribute("timescale");
			startNumber = payload->Attribute("startNumber");
			duration = payload->Attribute("duration");
			initialization = payload->Attribute("initialization");
			media = payload->Attribute("media");
		}

		std::string InitializationCreator(std::string representationId) {
			std::vector<std::string> args;
			args.push_back(representationId);
			return bbstream::core::replaceArgs(initialization, args);
		}

		std::string MediaCreator(std::string representationId, std::string number) {
			std::vector<std::string> args;
			args.push_back(representationId); args.push_back(number);
			return bbstream::core::replaceArgs(media, args);
		}
	};

	class AdaptationSet {
	public:
		AdaptationSetType setType;
		SegmentTemplate * segmentTemplate;
		std::vector<Representation> representationSet;

		AdaptationSet(const tinyxml2::XMLElement * payload) {
			std::string t = payload->Attribute("contentType");
			if (t.compare("video") == 0) {
				setType = AdaptationSetType::VIDEO;
			}
			else if (t.compare("audio") == 0) {
				setType = AdaptationSetType::AUDIO;
			}

			segmentTemplate = new SegmentTemplate(payload->FirstChildElement("SegmentTemplate"));

			for (const tinyxml2::XMLElement * child = payload->FirstChildElement("Representation"); child; child = child->NextSiblingElement("Representation")) {
				Representation representation = Representation(child, setType);
				representationSet.push_back(representation);
			}
		}
	};

	class Dash {
		tinyxml2::XMLDocument doc;
		std::vector<AdaptationSet> sets;
		std::string baseUrl;
	public:
		Dash() {

		}

		Dash(const char * payload) {
			doc.Parse(payload); // Parse the raw MPD manifest from memory
			tinyxml2::XMLElement * manifest = doc.FirstChildElement("MPD");

			// xmlDoc->FirstChildElement("MPD")->Attribute("publishTime");
			// Get base URL of other manifests as well as media files
			baseUrl = manifest->FirstChildElement("BaseURL")->GetText();

			// BBC Live streams only contain a single period, therefore we will only look for one.
			tinyxml2::XMLElement * period = manifest->FirstChildElement("Period");

			// Iterate through the available AdaptationSet(s)
			for (const tinyxml2::XMLElement * child = period->FirstChildElement("AdaptationSet"); child; child = child->NextSiblingElement("AdaptationSet")) {
				//std::cout << child->Attribute("contentType") << '\n';
				AdaptationSet set = AdaptationSet(child);

				/*
				for (int i = 0; i < set.representationSet.size(); i++) {
					Representation r = set.representationSet.at(i);
					switch (set.setType) {
					case VIDEO:
						std::cout << "ID: " << r.id << ", Width: " << r.width << ", Height: " << r.height << ", Bandwidth: " << r.bandwidth << ", Framerate: " << r.frameRate << '\n';
						break;
					case AUDIO:
						std::cout << "ID: " << r.id << ", Bandwidth: " << r.bandwidth << '\n';
						break;
					}
				}
				*/

				sets.push_back(set);
			}
		}

		tinyxml2::XMLDocument * getDoc() {
			return &doc;
		}

		std::vector<AdaptationSet> getSets() {
			return sets;
		}

		std::string getBaseURL() {
			return baseUrl;
		}
	};
}}}