#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string dam_header[] = {"Name", "Height", "Capacity (MW)", "Year of completion", "Reservoir formed", "River"};
        string Columbia_dams[14][6] = {{"Mica Dam", "240m (790ft)", "2,805", "1973", "Kinbasket Lake", "Columbia"}, 
                        {"Revelstoke Dam", "175m (574ft)", "2,480", "1984", "Revelstoke Lake", "Columbia"}, 
                        {"Keenleyside Dam", "52m (171ft)", "185", "1968", "Raised Arrow Lakes", "Columbia"}, 
                        {"Grand Coulee Dam", "550ft (170m)", "6,809", "1941 / 1974", "Franklin D. Roosevelt Lake", "Columbia"}, 
                        {"Chief Joseph Dam", "236ft (72m)", "2,620", "1955", "Rufus Woods Lake", "Columbia"}, 
                        {"Wells Dam", "160ft (49m)", "840", "1967", "Lake Pateros", "Columbia"}, 
                        {"Rocky Reach Dam", "130ft (40m)", "1,287", "1961", "Lake Entiat", "Columbia"}, 
                        {"Rock Island Dam", "135ft (41m)", "660", "1933", "Rock Island Pool", "Columbia"}, 
                        {"Wanapum Dam", "185ft (56m)", "1,092", "1963", "Lake Wanapum", "Columbia"}, 
                        {"Priest Rapids Dam", "178ft (54m)", "955.6", "1961", "Priest Rapids Lake", "Columbia"}, 
                        {"McNary Dam", "183ft (56m)", "1,133", "1954", "Lake Wallula", "Columbia"}, 
                        {"John Day Dam", "184ft (56m)", "2,485", "1971", "Lake Umatilla", "Columbia"}, 
                        {"The Dalles Dam", "260ft (79m)", "2,038", "1957", "Lake Celilo", "Columbia"}, 
                        {"Bonneville Dam", "197ft (60m)", "1,190", "1937 / 1981", "Lake Bonneville", "Columbia"}};
        
        string Snake_dams[20][6] = {{"Jackson Lake Dam", "65.5ft (20.0m)", "0", "1911 / 1916 / 1989", "Jackson Lake", "Snake"}, 
                    {"Palisades Dam", "270ft (82m)", "176.6", "1957", "Palisades Reservoir", "Snake"}, 
                    {"Gem State Dam", "40ft (12m)", "22.6", "1982", "", "Snake"}, 
                    {"American Falls Dam", "104ft (32m)", "112.4", "1927 / 1978", "American Falls Reservoir", "Snake"}, 
                    {"Minidoka Dam", "86ft (26m)", "28.5", "1909-1942", "Lake Walcott", "Snake"}, 
                    {"Milner Dam", "38ft (12m)", "59.5", "1905", "Milner Lake", "Snake"}, 
                    {"Twin Falls Dam", "25ft (7.6m)", "52.9", "1935 / 1995", "Twin Falls Reservoir", "Snake"}, 
                    {"Shoshone Falls Dam", "16ft (4.9m)", "64", "1907", "Shoshone Falls Reservoir", "Snake"}, 
                    {"Upper Salmon Falls Dam", "18ft (5.5m)", "34.5", "1937 / 1947", "Upper Salmon Falls Reservoir", "Snake"}, 
                    {"Lower Salmon Falls Dam", "38ft (12m)", "60", "1910 / 1949", "Lower Salmon Falls Reservoir", "Snake"}, 
                    {"Bliss Dam", "84ft (26m)", "75", "1950", "Bliss Reservoir", "Snake"}, 
                    {"C. J. Strike Dam", "115ft (35m)", "82.8", "1952", "C. J. Strike Reservoir", "Snake"}, 
                    {"Swan Falls Dam", "107ft (33m)", "25", "1901", "Swan Falls Reservoir", "Snake"}, 
                    {"Brownlee Dam", "420ft (130m)", "585", "1959 / 1980", "Brownlee Reservoir", "Snake"}, 
                    {"Oxbow Dam", "175ft (53m)", "220", "1961", "Oxbow Reservoir", "Snake"}, 
                    {"Hells Canyon Dam", "330ft (100m)", "450", "1967", "Hells Canyon Reservoir", "Snake"}, 
                    {"Lower Granite Dam", "181ft (55m)", "932", "1975 / 1987", "Lower Granite Lake", "Snake"}, 
                    {"Little Goose Dam", "253ft (77m)", "932", "1970", "Lake Bryan", "Snake"}, 
                    {"Lower Monumental Dam", "152ft (46m)", "930", "1969", "Lake Herbert G. West", "Snake"}, 
                    {"Ice Harbor Dam", "213ft (65m)", "693", "1961 / 1976", "Lake Sacajawea", "Snake"}};
                    
        string Salmon_dams[2][6] = {{"Goose Lake Dam (Goose Creek)", "26ft (7.9m)", "0", "1924", "Goose Lake", "Salmon"}, 
                        {"Brundage Dam (Brundage Creek(Goose Creek))", "64ft (20m)", "0", "1989", "Brundage Reservoir", "Salmon"}};
                        
        string Owyhee_dams[9][6] = {{"Wild Horse Dam", "114ft (35m)", "0", "1937 / 1969", "Wild Horse Reservoir", "Owyhee"}, 
                        {"Antelope Reservoir Dam (Antelope Creek (Jordan Creek))", "60ft (18m)", "0", "1923", "Antelope Reservoir", "Owyhee"}, 
                        {"Owyhee Dam", "417ft (127m)", "5,8,2", "1932", "Lake Owyhee", "Owyhee"}, 
                        {"Wilson Reservoir Dam (Wilson Creek)", "34ft (10m)", "0", "", "Wilson Reservoir", "Owyhee"}, 
                        {"Bull Run Dam (Bull Run Creek)", "69ft (21m)", "0", "", "Bull Run Reservoir", "Owyhee"}, 
                        {"Dry Creek Dam (Indian Creek)", "70ft (21m)", "0", "", "Dry Creek Reservoir", "Owyhee"}, 
                        {"Rawhide Reservoir Dam (Indian Creek)", "33ft (10m)", "0", "", "Rawhide Reservoir", "Owyhee"}, 
                        {"Sheep Creek Dam (Sheep Creek)", "29ft (8.8m)", "0", "1966", "Sheep Creek Reservoir", "Owyhee"}, 
                        {"Chimney Creek Dam (Fourmile Creek)", "20ft (6.1m)", "0", "", "Desert Ranch Reservoir", "Owyhee"}};
        
        string Malheur_dams[6][6] = {{"Warm Springs Dam", "106ft (32m)", "proposed 2.7", "1919", "Warm Springs Reservoir", "Malheur"}, 
                        {"Agency Valley Dam (North Fork Malheur River)", "110ft (34m)", "proposed 2.0", "1935", "Beulah Reservoir", "Malheur"}, 
                        {"Harper Diversion Dam", "12ft (3.7m)", "0", "1930", "Harper Diversion Pool", "Malheur"}, 
                        {"Bully Creek Dam (Bully Creek)", "121ft (37m)", "0", "1963", "Bully Creek Reservoir", "Malheur"}, 
                        {"Bully Creek Diversion Dam (Bully Creek)", "4ft (1.2m)", "0", "1964", "Bully Creek Diversion Pool", "Malheur"}, 
                        {"Willow Creek Reservoir #3 Dam (Willow Creek)", "110ft (34m)", "0", "1944", "Malheur Reservoir", "Malheur"}};
                        
        string Wallowa_dams[1][6] = {{"Wallowa Lake Dam", "40ft (12m)", "0", "1931", "Raised Wallowa Lake", "Wallowa"}};
        
        string Powder_dams[2][6] = {{"Mason Dam", "173ft (53m)", "proposed 3.4", "1968", "Philips Lake", "Powder"}, 
                        {"Thief Valley Dam", "73ft (22m)", "0", "1932", "Thief Valley Reservoir", "Powder"}};
                        
        string Blackfoot_dams[1][6] = {{"Blackfoot Dam", "44ft (13m)", "0", "1911", "Blackfoot Reservoir", "Blackfoot"}};
        
        string Henrys_Fork_dams[5][6] = {{"Henrys Lake Dam", "18ft (5.5m)", "0", "1923", "Raised Henrys Lake", "Henrys Fork"}, 
                        {"Island Park Dam", "94ft (29m)", "4.8", "1938", "Island Park Reservoir", "Henrys Fork"}, 
                        {"Buffalo River Dam (Buffalo River)", "12ft (3.7m)", "0.25", "1980", "Buffalo Dam Pool", "Henrys Fork"}, 
                        {"Ashton Dam", "56.6ft (17.3m)", "6.85", "1913", "Ashton Dam Lake", "Henrys Fork"}, 
                        {"Chester Dam (Crosscut Diversion Dam)", "14.5ft (4.4m)", "3.3", "1938", "Chester Dam Pool", "Henrys Fork"}};
                        
        string Fall_dams[1][6] = {{"Grassy Lake Dam (Grassy Creek)", "118ft (36m)", "0", "1939", "Grassy Lake", "Fall"}};
        
        string Portneuf_dams[1][6] = {{"Portneuf Dam", "47ft (14m)", "0", "1912", "Chesterfield Reservoir", "Portneuf"}};
        
        string Salmon_Falls_Creek_dams[2][6] = {{"Salmon Falls Dam", "217ft (66m)", "0", "1911", "Salmon Falls Creek Reservoir", "Salmon Falls Creek"}, 
                        {"Cedar Creek Dam (Cedar Creek)", "84ft (26m)", "0", "1920", "Cedar Creek Reservoir", "Salmon Falls Creek"}};
                        
        string Boise_dams[6][6] = {{"Arrowrock Dam", "350ft (110m)", "15", "1915", "Arrowrock Reservoir", "Boise"}, 
                        {"Lucky Peak Dam", "340ft (100m)", "101.25", "1955", "Lucky Peak Lake", "Boise"}, 
                        {"Boise River Diversion Dam", "68ft (21m)", "3.3", "1908", "Boise River Diversion Dam Pool", "Boise"}, 
                        {"Barber Dam", "25ft (7.6m)", "4.14", "1904", "Barber Dam Pool", "Boise"}, 
                        {"Anderson Ranch Dam", "456ft (139m)", "40", "1947", "Anderson Ranch Reservoir", "Boise"}, 
                        {"Little Camas Dam (Little Camas Creek)", "44ft (13m)", "0", "1912", "Little Camas Reservoir", "Boise"}};
        
        string Goose_Creek_dams[1][6] = {{"Oakley Dam", "139ft (42m)", "0", "1916", "Lower Goose Creek Reservoir", "Goose Creek"}};
        
        string Weiser_dams[4][6] = {{"Lost Valley Dam (Lost Creek(West Fork Weiser River))", "52ft (16m)", "0", "1929", "Lost Valley Reservoir", "Weiser"}, 
                        {"C Ben Ross Dam (Little Weiser River)", "56ft (17m)", "0", "1937", "Ben Ross Reservoir", "Weiser"}, 
                        {"Crane Creek Dam (Crane Creek)", "55ft (17m)", "0", "1912", "Crane Creek Reservoir", "Weiser"}, 
                        {"Mann Creek Dam (Mann Creek)", "148ft (45m)", "0", "1967", "Mann Creek Reservoir", "Weiser"}};
                    
        string Burnt_dams[1][6] = {{"Unity Dam", "82ft (25m)", "proposed 0.8", "1938", "Unity Reservoir", "Burnt"}};
        
        string Willow_dams[1][6] = {{"Ririe Dam", "253ft (77m)", "0", "1977", "Ririe Reservoir", "Willow"}};
        
        string Payette_dams[9][6] = {{"Black Canyon Diversion Dam", "183ft (56m)", "10.2", "1924", "Black Canyon Reservoir", "Payette"}, 
                        {"Upper Payette Lake Dam", "18ft (5.5m)", "0", "1952", "Upper Payette Lake", "Payette"}, 
                        {"Granite Lake Dam (Fisher Creek)", "28ft (8.5m)", "0", "1963", "Granite Lake", "Payette"}, 
                        {"Payette Lake Dam", "8.2ft (2.5m)", "0", "1943", "Raised Payette Lake", "Payette"}, 
                        {"Little Payette Lake Dam (Lake Fork)", "15.8ft (4.8m)", "0", "1926", "Little Payette Lake", "Payette"}, 
                        {"Cascade Dam", "107ft (33m)", "12.8", "1948", "Lake Cascade", "Payette"}, 
                        {"Sage Hen Dam(Sage Hen Creek(Second Fork Squaw Creek))", "38ft (12m)", "0", "1938", "Sage Hen Reservoir", "Payette"}, 
                        {"Paddock Valley Dam (Little Willow Creek)", "43ft (13m)", "0", "1949", "Paddock Valley Reservoir", "Payette"}, 
                        {"Deadwood Dam (Deadwood River)", "183ft (56m)", "0", "1931", "Deadwood Reservoir", "Payette"}};

        string Clearwater_dams[1][6] = {{"Dworshak Dam", "717ft (219m)", "400", "1973", "Dworshak Reservoir", "Clearwater"}};
        
        string Malad_dams[2][6] = {{"Upper Malad River Dam", "124.1ft (37.8m)", "8.27", "1948", "Malad Gorge State Park", "Malad"}, 
                        {"Lower Malad River Dam", "152.0ft (46.3m)", "13.50", "1911", "Malad Gorge State Park", "Malad"}};
                        
        string Big_Wood_dams[1][6] = {{"Magic Dam", "128ft (39m)", "9", "1910", "Magic Reservoir", "Big Wood"}};
        
        string Camas_Creek_dams[1][6] = {{"Mormon Dam (McKinney Creek)", "23ft (7.0m)", "0", "1908", "Mormon Reservoir", "Camas Creek"}};
        
        string Little_Wood_dams[2][6] = {{"Little Wood River Dam", "169ft (52m)", "3", "1962", "Little Wood Reservoir", "Little Wood"}, 
                        {"Fish Creek Dam (Fish Creek)", "88ft (27m)", "0", "1923", "Fish Creek Reservoir", "Little Wood"}};
                        
        string Kootenay_dams[7][6] = {{"Libby Dam", "420ft (130m)", "604", "1972", "Lake Koocanusa", "Kootenay"}, 
                        {"Corra Linn Dam", "16m (52ft)", "51", "1932", "raised Kootenay Lake", "Kootenay"}, 
                        {"Upper Bonnington Falls Dam", "21m (69ft)", "53", "1907", "", "Kootenay"}, 
                        {"Lower Bonnington Falls Dam", "21m (69ft)", "25", "1925", "", "Kootenay"}, 
                        {"South Slocan Dam", "18m (59ft)", "57", "1928", "", "Kootenay"}, 
                        {"Kootenay Canal Generating Station", "84m (276ft)", "583", "1976", "", "Kootenay"}, 
                        {"Brilliant Dam", "42.6m (140ft)", "260", "1944 / 2007", "", "Kootenay"}};
                    
        string Bull_dams[1][6] = {{"Aberfeldie Dam", "90ft (27m)", "24", "1922 (rebuilt 1953)", "Aberfeldie Dam Pool", "Bull"}};
            
        string Elk_dams[1][6] = {{"Elko Dam", "52ft (16m)", "12", "1924", "Elko Dam Pool", "Elk"}};
        
        string Duncan_dams[1][6] = {{"Duncan Dam", "130ft (40m)", "0", "1967", "raised Duncan Lake", "Duncan"}};
    
        string Mark_Creek_dams[1][6] = {{"Upper Mark Creek Dam", "21.5m (71ft)", "0", "1994", "Mark Creek Dam Reservoir", "Mark Creek"}};
        
        string Pend_Oreille_dams[10][6] = {{"Thompson Falls Dam", "110ft (34m)", "94", "1915", "Thompson Falls Reservoir", "Pend Oreille"}, 
                        {"Noxon Rapids Dam", "260ft (79m)", "527", "1959", "Noxon Reservoir", "Pend Oreille"}, 
                        {"Cabinet Gorge Dam", "208ft (63m)", "255", "1952", "Cabinet Gorge Reservoir", "Pend Oreille"}, 
                        {"Pend Oreille", "Pend Oreille", "Pend Oreille", "Pend Oreille", "Pend Oreille", "Pend Oreille"}, 
                        {"Albeni Falls Dam", "90ft (27m)", "42", "1955", "Raised Lake Pend Oreille 11.5ft (3.5m)", "Pend Oreille"}, 
                        {"Box Canyon Dam", "62ft (19m)", "90", "1956", "Box Canyon Reservoir", "Pend Oreille"}, 
                        {"Boundary Dam", "340ft (100m)", "1,040", "1967", "Boundary Lake", "Pend Oreille"}, 
                        {"Seven Mile Dam", "79.2m (260ft)", "848", "1979", "", "Pend Oreille"}, 
                        {"Waneta Dam", "75.9m (249ft)", "450", "1954", "", "Pend Oreille"}, 
                        {"Waneta Dam Expansion", "75.9m (249ft)", "335", "2015", "", "Pend Oreille"}};
    
        string Flathead_dams[2][6] = {{"Hungry Horse Dam", "564ft (172m)", "428", "1953", "Hungry Horse Reservoir", "Flathead"}, 
                        {"Seli’š Ksanka Qlispe’ Dam (Kerr Dam)", "205ft (62m)", "188", "1938", "Raised Flathead Lake 10ft (3.0m)", "Flathead"}};
        
        string Deschutes_dams[5][6] = {{"Crane Prairie Dam", "36ft (11m)", "0", "1940", "Crane Prairie Reservoir", "Deschutes"}, 
                        {"Wickiup Dam", "100ft (30m)", "0", "1949", "Wickiup Reservoir", "Deschutes"}, 
                        {"Round Butte Dam", "440ft (130m)", "247.12", "1964", "Lake Billy Chinook", "Deschutes"}, 
                        {"Pelton Dam", "204ft (62m)", "100.8", "1957", "Lake Simtustus", "Deschutes"}, 
                        {"Pelton Reregulating Dam", "88ft (27m)", "18.9", "1958", "", "Deschutes"}};
                
        string Yakima_dams[8][6] = {{"Keechelus Dam", "128ft (39m)", "0", "1917", "Raised Keechelus Lake", "Yakima"}, 
                        {"Easton Diversion Dam", "66ft (20m)", "0", "1929", "Lake Easton", "Yakima"}, 
                        {"Unnamed Diversion Dam", "", "0", "", "", "Yakima"}, 
                        {"Roza Diversion Dam", "67ft (20m)", "12", "1939", "", "Yakima"}, 
                        {"Wapato Dam", "19ft (5.8m)", "0", "", "Wapato Reservoir", "Yakima"}, 
                        {"Sunnyside Dam", "8ft (2.4m)", "0", "1907", "", "Yakima"}, 
                        {"Prosser Dam", "9ft (2.7m)", "0", "1904", "", "Yakima"}, 
                        {"Wannawish Dam", "6.6ft (2.0m)", "0", "1892", "", "Yakima"}};
    
        string Cle_Elum_dams[1][6] = {{"Cle Elum Dam", "165ft (50m)", "0", "1933", "Raised Cle Elum Lake", "Cle Elum"}};
        
        string Kachess_dams[1][6] = {{"Kachess Dam", "115ft (35m)", "0", "1912", "Raised Kachess Lake", "Kachess"}};
        
        string Bumping_dams[1][6] =  {{"Bumping Lake Dam", "60ft (18m)", "0", "1910", "Raised Bumping Lake", "Bumping"}};
        
        string Tieton_dams[2][6] = {{"Clear Creek Dam (North Fork Tieton)", "83ft (25m)", "0", "1915", "Clear Lake", "Tieton"}, 
                        {"Tieton Dam", "319ft (97m)", "0", "1925", "Rimrock Lake", "Tieton"}};
        
        string Willamette_dams[5][6] = {{"Willamette Falls Dam", "20ft (6.1m)", "15.18", "1888", "", "Willamette"}, 
                        {"Hills Creek Dam", "304ft (93m)", "30", "1961", "Hills Creek Reservoir", "Willamette"}, 
                        {"Lookout Point Dam", "276ft (84m)", "150", "1954", "Lookout Point Lake", "Willamette"}, 
                        {"Fall Creek Dam", "180ft (55m)", "0", "1966", "Fall Creek Reservoir", "Willamette"}, 
                        {"Dexter Dam", "93ft (28m)", "15", "1954", "Dexter Reservoir", "Willamette"}};
            
        string Santiam_dams[5][6] = {{"North Santiam", "North Santiam", "North Santiam", "North Santiam", "North Santiam", "Santiam"}, 
                        {"Detroit Dam", "463ft (141m)", "100", "1953", "Detroit Reservoir", "Santiam"}, 
                        {"Big Cliff Dam", "191ft (58m)", "18", "1953", "Big Cliff Reservoir (reregulation for Detroit Reservoir)", "Santiam"},
                        {"Green Peter Dam", "327ft (100m)", "80", "1968", "Green Peter Reservoir", "Santiam"}, 
                        {"Foster Dam", "126ft (38m)", "20", "1968", "Foster Reservoir (reregulation for Green Peter Reservoir)", "Santiam"}};

        string McKenzie_dams[7][6] = {{"Carmen Diversion Dam", "17ft (5.2m)", "0", "1963", "Carmen Reservoir", "McKenzie"}, 
                        {"Trail Bridge Dam", "90ft (27m)", "10", "1963", "Trail Bridge Reservoir", "McKenzie"}, 
                        {"Smith Dam (Smith River)", "250ft (76m)", "104.5", "1963", "Smith Reservoir", "McKenzie"}, 
                        {"Cougar Dam (South Fork)", "425ft (130m)", "25", "1963", "Cougar Reservoir", "McKenzie"}, 
                        {"Blue River Dam (Blue River)", "270ft (82m)", "0", "1969", "Blue River Reservoir", "McKenzie"}, 
                        {"Leaburg Dam", "20ft (6.1m)", "15.9", "1929", "Leaburg Reservoir", "McKenzie"}, 
                        {"Walterville Dam", "24ft (7.3m)", "9", "1911", "Walterville Reservoir", "McKenzie"}};
        
        string Coast_Fork_dams[2][6] = {{"Cottage Grove Dam", "95ft (29m)", "0", "1942", "Cottage Grove Lake", "Coast Fork"}, 
                        {"Dorena Dam (Row River)", "145ft (44m)", "7.51", "1949", "Dorena Lake", "Coast Fork"}};

        string Spokane_dams[7][6] = {{"Post Falls Dam", "64ft (20m)", "15", "1908", "Raised Lake Coeur d'Alene", "Spokane"}, 
                        {"Upriver Dam", "", "17.7", "1894 / 1933", "Upriver Dam Reservoir", "Spokane"}, 
                        {"Upper Falls Dam", "35ft (11m)", "10", "1922", "Upper Falls Reservoir", "Spokane"}, 
                        {"Monroe Street Dam", "24ft (7.3m)", "15", "1890", "", "Spokane"}, 
                        {"Nine Mile Dam", "58ft (18m)", "26", "1908", "Nine Mile Reservoir", "Spokane"}, 
                        {"Long Lake Dam", "213ft (65m)", "71", "1915", "Long Lake", "Spokane"}, 
                        {"Little Falls Dam", "57ft (17m)", "36", "1911", "Little Falls Pool", "Spokane"}};

        string Cowlitz_dams[3][6] = {{"Cowlitz Falls Dam", "140ft (43m)", "70", "1994", "Lake Scanewa", "Cowlitz"}, 
                        {"Mossyrock Dam", "606ft (185m)", "300", "1968", "Riffe Lake", "Cowlitz"}, 
                        {"Mayfield Dam", "250ft (76m)", "162", "1963", "Lake Mayfield", "Cowlitz"}};

        string Lewis_dams[4][6] = {{"Swift Dam", "512ft (156m)", "240", "1958", "Swift Reservoir", "Lewis"}, 
                        {"Swift No. 2 Dam", "83ft (25m)", "70", "1959", "", "Lewis"}, 
                        {"Yale Dam", "323ft (98m)", "134", "1953", "Yale Lake", "Lewis"}, 
                        {"Merwin Dam", "313ft (95m)", "136", "1931", "Lake Merwin", "Lewis"}};

        string Spillimacheen_dams[1][6] = {{"Spillimacheen Dam", "14.5m (48ft)", "4", "1955", "Spillimacheen Dam Pool", "Spillimacheen"}};
        
        string Wenatchee_dams[1][6] = {{"Tumwater Canyon Dam", "23ft (7.0m)", "0", "1909", "Lake Jolanda", "Wenatchee"}};

        string Chelan_dams[1][6] = {{"Lake Chelan Dam", "40ft (12m)", "59.2", "1892–1903 / 1927", "Raised Lake Chelan", "Chelan"}};
        return 0;
}