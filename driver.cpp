#include "tonyTotts.h"
#include <string>
#include <iostream>
#include <chrono> // purely for aesthetic
#include <thread> // purely for aesthetic
using namespace std;
using namespace this_thread;
using namespace chrono;

// Cutscenes
void title();
void intro();
void rickysHouse();
void motelTicks();
void MayorIntro();
void rideToGruffs();
void gruffIntro();

// Convenience
void enter();

// Functionality
int validateAnswer(string answer, int highest, int lowest);
int viewInventory(TonyTotts& you, bool includeExit);

int main(){
    TonyTotts you;
    string allEvidence[15][2] = {{"Case File", "ICUP Case 07734 \nSome sick freak has been breaking into houses, throwing their perfectly good milk down the sink, and replacing it with rotten milk. \nSo far, there have been 20 victims. All but one Mr. Ricky Green have been inconsolable. \nHis house is the scene of the ongoing investigation."},
        {"Raccoon Fur", "A raccoon's fur, stuck onto the chips of Ricky's back door. \nYour puppy nose can identify who it belongs to without a doubt: Stripes the raccoon."},
        {"A Fake Mustache", "A fake mustache with a \"Fancyman Fancypants Fake Stache Emporium\" tag. \nIt reeks of Stripes."},
        {"Profile: Stripes", "Anthony 'Stripes' Chlebek. This guy is a notoriously sneaky raccoon who does any job for some good cheese..."},
        {"Cheese Wheel Slice", "A beautiful slice of silky cheese... \nYummy, but I wish I new more about it."},
        {"Profile: Mayor Langstram", "Mayor Ethan von Isaiah Langstram, a well-rounded Mayor who loves milk just like everyone else in town! \nHe's a fancy white cat with a whimsical and large twirly mustache and a matching black tophat. \nApparently, he also is a connoisseur of cheese?"},
        {"Info: Gruff's Goat Milk Galore", "A highly successful goat milk factory. According to the Mayor, there's no where else this cheese could be from."},
        {"Info: A Broken Window", "We're not the only ones who wanted to pay Gruff's a visit..."},
        {"Profile: Billy Gruff", "Mr. Billy G. Gruffman is a self-made business man who created this business one town over from Iceberg City. \nHe seems a bit nervous about the whole situation. \nIs this reasonable... or is it suspicious?"},
        {"Cow Success Graph", "As cow milk succeeds, goat milk fails. That's not good for Gruff."},
        {"A Business Decree", "Billy's fancy business decree. \nIf he gets into a position where he could not manage the company, the next authority figure of the company gets power."},
        {"Info: A Former Associate...?", "According to Billy, he could only think over one person who could be responsible for all this. \nHe formerly had a business partner, Ethnyan, who embezzled his money decades ago, so he got the guy locked up. \nHe never actually fired him, though. \nThen he disappeared from jail without a trace..."},
        {"Photo with Associate", "A young Billy with a business partner: a young, smooth-faced white cat. \n\"Signed, Billy & Ethnyan\""},
        {"Bucket of Water", "Spillable!"},
        {"Strange Elixir-looking Bucket of Water", "Also spillable!"}
    };

    title();
    intro();

    // Tutorial Scene Part One //
    cout << "[ T U T O R I A L ! ]" << endl;
    cout << "*You are Tony Totts! As you investigate, you will be presented with lots of choices! Some are good for your job, and some are bad.\nAs a rookie detective, you need to prove yourself worthy of working alongside Detective Blackwood." << endl;
    cout << "Here, you can make your first choice. There is no wrong choice that'll permanently affect the story here, but later choices may impact your reputation.*" << endl << endl;
    bool scene = true;
    bool choice1 = false, choice2 = false;
    while(scene){
        cout << "Choices: " << endl;
        if(!choice1){
            cout << "    1. [Take folder]" << endl;
        }else{
            cout << "    1. [View inventory]" << endl;
        }
        cout << "    2. \"So, the weather, huh?\"" << endl;
        if(choice1){
            cout << "    3. [Begin investigation]" << endl;
        }
        cout << "Enter choice: ";
        string input;
        int choice = -1;
        getline(cin, input);
        if(choice1){
            choice = validateAnswer(input, 3, 1);
        }else{
            choice = validateAnswer(input, 2, 1);
        }
        while(choice == -1){
            cout << "This is your FIRST decision, Tony... Try again: ";
            getline(cin, input);
            if(choice1 == true){
                choice = validateAnswer(input, 3, 1);
            }else{
                choice = validateAnswer(input, 2, 1);
            }
        }

        switch(choice){
            case 1:
                if(!choice1){
                    int evidence = you.addEvidence(allEvidence[0][0], allEvidence[0][1]);
                    you.viewEvidence(evidence);
                    sleep_for(milliseconds(1000));
                    choice1 = true;
                }else{
                    viewInventory(you, true);
                }
                enter();
                break;
            case 2:
                cout << endl;
                if(!choice2){
                    choice2 = true;
                    cout << "TONY: So, the weather, huh?" << endl << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "BLACKWOOD: ... " << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "BLACKWOOD: ... " << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "BLACKWOOD: It's alright." << endl << endl;
                    sleep_for(milliseconds(1000));
                }else{
                    cout << "TONY: So, the weather, HUH?" << endl << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "BLACKWOOD: ... " << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "BLACKWOOD: ... " << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "BLACKWOOD: Just let me know when you're ready." << endl << endl;
                    sleep_for(milliseconds(1000));
                }
                break;
            case 3:
                scene = false;
                cout << endl;
        }
    }

    // Tutorial Scene Part Two //
    cout << "*Sometimes, you'll have to show people evidence to advance the story!*" << endl << endl;
    scene = true;
    while(scene){
        bool failed = false;
        sleep_for(milliseconds(1000)); 
        cout << "BLACKWOOD: Now, where do we start? " << endl;
        sleep_for(milliseconds(1000)); 
        int choice = viewInventory(you, false);
        while(choice != 2){
            cout << endl;
            if(!failed){
                failed = true;
                cout << "BLACKWOOD: Uh huh... I know you're a detective. No need to show me the badge, bucko. " << endl;
                sleep_for(milliseconds(1000)); 
                cout << "TONY: Oh! Right! Sorry, sir." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "*Do you have anything in your inventory that says where to start the investigation?*" << endl;
            }else{
                cout << "BLACKWOOD: Come on, you already showed me this." << endl;
                sleep_for(milliseconds(1000)); 
                cout << "TONY: Uh-- Yeah! Of course! My hand... slipped." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "*Normally, this would hurt your reputation! Three strikes and you're out! He's looking for the case file.*" << endl;
            }
            choice = viewInventory(you, false);
        }
        scene = false;
        cout << "TONY: Well, the case file says that Ricky Green's house is where the investigation is ongoing!" << endl << endl;
        sleep_for(milliseconds(1000)); 
        cout << "BLACKWOOD: Absolutely right, kid. Sounds like we should head over." << endl;
        if(!failed){
            sleep_for(milliseconds(1000));
            cout << "BLACKWOOD: It's a tough job, but it looks like you're already a natural." << endl;
        }
        cout << endl;
        sleep_for(milliseconds(1000));
        cout << "[ T U T O R I A L   C O M P L E T E !]" << endl;
        cout << "*Now it looks like you got the hang of this, so now you're on your own!*" << endl;
        enter();
    }

    // Ricky Green's //
    rickysHouse();
    scene = true;
    choice1 = false, choice2 = false;
    bool choice3 = false, jaccuse = false;
    while(scene){
        cout << "Choices: " << endl;
        cout << "    1. [View inventory]" << endl;
        if(!choice1){
            cout << "    2. \"Mr. Green, who might've done this?\"" << endl;
        }else{
            if(!choice2){
                cout << "    2. \"Mr. Green, how did you hear the break-in?\"" << endl;
            }else{
                if(!jaccuse){
                    cout << "    2. \"I think YOU did it, Ricky Green!\"" << endl;
                }else{
                    cout << "    2. \"I'd like to apologize...\"" << endl;
                }
            }
        }
        cout << "    3. [Investigate kitchen]" << endl;
        if(choice1){
            cout << "    4. [Check backdoor]" << endl;
        }
        if(choice3){
            cout << "    5. [Consult Blackwood]" << endl;
        }
        cout << "Enter choice: ";
        string input;
        int choice = -1, numChoices = 3;
        getline(cin, input);
        if(choice1){
            numChoices++;
            if(choice2){
                numChoices++;
            }
        }
        choice = validateAnswer(input, numChoices, 1);
        while(choice == -1){
            cout << "Try again: ";
            getline(cin, input);
            choice = validateAnswer(input, numChoices, 1);
        }

        switch(choice){
            case 1:
                viewInventory(you, true);
                enter();
                break;
            case 2:
                cout << endl;
                if(!choice1){
                    choice1 = true;
                    cout << "TONY: Mr. Green, is there anything you know about who might have done this?" << endl << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "RICKY: I couldn't tell you much. I had no clue my house was even being broken into. " << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "RICKY: Well, until... " << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "RICKY: I think I heard the monster slam the backdoor on their hand." << endl << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "TONY: I see." << endl;
                    sleep_for(milliseconds(1000)); 
                    cout << "TONY: Thank you, Mr. Green." << endl << endl;
                    sleep_for(milliseconds(1000)); 
                    choice1 = true;
                }else{
                    if(!choice2){
                        cout << "TONY: Mr. Green, how did you hear the break-in?" << endl << endl;
                        sleep_for(milliseconds(1000)); 
                        cout << "RICKY: I just got done misting up in the bathroom. " << endl;
                        sleep_for(milliseconds(1000)); 
                        cout << "RICKY: A fine mist is good for hydrating chameleons, y'know." << endl << endl;
                        sleep_for(milliseconds(1000)); sleep_for(milliseconds(1000)); 
                        cout << "TONY: Hm..." << endl << endl;
                        sleep_for(milliseconds(1000)); 
                        choice2 = true;
                    }else{
                        if(!jaccuse){
                            cout << "TONY: I think it was YOU, Ricky Green!" << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "RICKY: HUH?" << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "RICKY: I can't believe this!" << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "RICKY: This is OUTRAGEOUS!" << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "BLACKWOOD: Hey! What's all this yelling for?" << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "RICKY: This detective accused ME of the crime!" << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "BLACKWOOD: ..." << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "RICKY: ..." << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "TONY: ..." << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "BLACKWOOD: This is a demerit, Totts. Apologies for his behavior, Mr. Green." << endl << endl;
                            sleep_for(milliseconds(1000));
                            you.wompWomp();
                            jaccuse = true;
                            sleep_for(milliseconds(1000));
                        }else{
                            cout << "TONY: I would like to apologize" << endl << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "RICKY: I'm sure you would, tough guy." << endl;
                            sleep_for(milliseconds(1000)); 
                            cout << "RICKY: You betta find the guy who did this." << endl << endl;
                            sleep_for(milliseconds(1000));
                        }
                    }
                }
                break;
            case 3:
                cout << endl;
                cout << "The scene is horrific. The stench of rotten milk is creeping out of the fridge." << endl;
                cout << "It will probably take poor Mr. Green months to get the smell out." << endl;
                cout << "At the sink, an empty carton of delectable cow's milk lies defeated. It has been completely drained down the sink, remnants still streaming." << endl;
                cout << "Hesistantly, Junior Detective Tony Totts opens the fridge." << endl << endl;
                sleep_for(milliseconds(1000)); 
                cout << "The smell punches him in the face. Putrid smells are especially cruel to a dog with keen senses." << endl;
                cout << "And all that work just to find no leads. Just a carton of rotten milk with an evil smile sharpied into the side." << endl << endl;
                sleep_for(milliseconds(1000)); 
                break;
            case 4:
                cout << endl;
                if(!choice3){
                    cout << "Following Ricky Green's lead, Tony investigated the back door..." << endl;
                    enter();
                    int evidence = you.addEvidence(allEvidence[1][0], allEvidence[1][1]);
                    you.viewEvidence(evidence);
                    sleep_for(milliseconds(1000)); 
                    enter();
                    choice3 = true;
                }else{
                    cout << "TONY: Man... Slamming the door on your hand must've hurt, huh Stripes?" << endl << endl;
                }
                break;
            case 5:
                cout << endl;
                cout << "BLACKWOOD: So, what've you got, kid?" << endl;
                if(jaccuse){
                    sleep_for(milliseconds(1000)); 
                    cout << "BLACKWOOD: ... Other than falsely accusing the victim of the crime." << endl;
                }
                cout << endl;
                sleep_for(milliseconds(1000)); 
                cout << "TONY: I found some fur. I can smell that it belongs to a very infamous raccoon." << endl << endl;
                sleep_for(milliseconds(1000)); 
                cout << "BLACKWOOD: Stripes." << endl << endl;
                sleep_for(milliseconds(1000)); 
                cout << "TONY: Exactly." << endl << endl;
                sleep_for(milliseconds(1000)); 
                cout << "BLACKWOOD: This sly raccoon is always up to something. We have to find him before he gets away again." << endl << endl;
                enter();
                scene = false;
        }
    }

    // Motel Ticks, Outside //
    motelTicks();
    scene = true;
    bool stripesArrested;
    while(scene){
        cout << "Choices:" << endl;
        cout << "    1. This can't be Stripes. Stripes doesn't have a mustache. \"Right, of course sir.\"" << endl;
        cout << "    2. [Sniff]" << endl;
        cout << "Enter choice: ";
        string input;
        int choice = -1, numChoices = 3;
        getline(cin, input);
        choice = validateAnswer(input, 2, 1);
        while(choice == -1){
            cout << "Try again: ";
            getline(cin, input);
            choice = validateAnswer(input, 2, 1);
        }
        cout << endl;
        int evidence = you.addEvidence(allEvidence[2][0], allEvidence[2][1]);
        switch(choice){
            case 1:
                sleep_for(milliseconds(1000));
                cout << "'Stripes doesn't have a mustache!' Tony thought. 'No point inconveniencing this random raccoon!'" << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: Right, of course sir." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "Tony innocently stepped aside. The hunched raccoon scurried past before breaking into a full sprint, leaving the door unlocked behind him." << endl;
                sleep_for(milliseconds(1000));
                cout << "The raccoon's fluffy mustache blew into the wind, glue flapping off the inside." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: ... That was weird" << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "Tony reached for the mustache." << endl << endl;
                sleep_for(milliseconds(1000));
                enter();

                you.viewEvidence(evidence);
                sleep_for(milliseconds(1000));
                enter();

                sleep_for(milliseconds(1000));
                cout << "TONY: ..." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "Blackwood walked over." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: ..." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "BLACKWOOD: Totts." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: ..." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "BLACKWOOD: Totts. What happened?" << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: I let Stripes go." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "BLACKWOOD: Oh my god." << endl << endl;
                sleep_for(milliseconds(1000));
                you.wompWomp();
                enter();
                stripesArrested = false;
                scene = false;
                break;
            case 2:
                sleep_for(milliseconds(1000));
                cout << "Sniff..." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "SNIFF..." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "Tony's eyes widened." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: You're no stranger at all! In fact--" << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "He quickly snatched at the mustache, ripping it off." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: You're STRIPES!" << endl << endl;
                sleep_for(milliseconds(1000));
                enter();

                you.viewEvidence(evidence);
                sleep_for(milliseconds(1000));
                enter();

                sleep_for(milliseconds(1000));
                cout << "TONY: I'm Junior Detective Totts of the ICUP, and police are on their way." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "STRIPES: Oh! Get off your high horse, detective..." << endl;
                sleep_for(milliseconds(1000));
                cout << "STRIPES: It was an obvious disguise..." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: Yeah, yeah... Why'd you do it?" << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "STRIPES: Why else? The chedda..." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: Who's paying you?" << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "Stripes shrugged, zipping his mouth shut. Blackwood walked up." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "BLACKWOOD: Hey, good job kid, you got the guy." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "Blackwood reached for his radio, calling in backup to arrest Stripes." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: Yeah, but he didn't plan it. He got paid to do it." << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "BLACKWOOD: By who?" << endl << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: He didn't say. We just gotta poke around and find out." << endl;
                sleep_for(milliseconds(1000));
                cout << "TONY: At least he left the door unlocked." << endl << endl;
                sleep_for(milliseconds(1000));
                enter();
                stripesArrested = true;
                scene = false;
                break;
        }

        sleep_for(milliseconds(1000));
        evidence = you.addEvidence(allEvidence[3][0], allEvidence[3][1]);
        you.viewEvidence(evidence);
        sleep_for(milliseconds(1000));
        enter();
    }

    // Motel Ticks, Stripes' Suite //
    scene = true;
    while(scene){
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: Wow..." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: Yeah..." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: His room is just... cheese." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: Let me just grab a sample... And a taste." << endl << endl;
        sleep_for(milliseconds(1000));
        enter();

        sleep_for(milliseconds(1000));
        int evidence = you.addEvidence(allEvidence[4][0], allEvidence[4][1]);
        you.viewEvidence(evidence);
        sleep_for(milliseconds(1000));
        enter();

        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: Do you know the Mayor, kid?" << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: Mayor Langstram! Yes! Why?" << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: He happens to be a cheese expert." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: Right, of course. I expect nothing else from the Mayor of such a milk-positive town." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: So..." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: Soo...?" << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: We should see him to see who manufactured the cheese.." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: Oh." << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: Right." << endl << endl;
        sleep_for(milliseconds(1000));
        enter();

        sleep_for(milliseconds(1000));
        evidence = you.addEvidence(allEvidence[5][0], allEvidence[5][1]);
        you.viewEvidence(evidence);
        sleep_for(milliseconds(1000));
        enter();
        scene = false;
    }

    // Mayor's Office //
    MayorIntro();
    scene = true;
    choice1 = false;
    bool accuseMayorEarly = false, strikeOut = false, showMayor = false;
    while(scene){
        if(!strikeOut){
            sleep_for(milliseconds(1000));
            cout << "MAYOR: So, how could I help you boys?" << endl << endl;
            sleep_for(milliseconds(1000));
            int choice = viewInventory(you, false);
            switch(choice){
                case 1: // Badge
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Very good, detective... I'm glad to have you on the force." << endl << endl;
                    sleep_for(milliseconds(1000));
                    cout << "BLACKWOOD: Totts." << endl;
                    sleep_for(milliseconds(1000));
                    cout << "BLACKWOOD: There's no need to show the Mayor that." << endl << endl;
                    enter();
                    break;
                case 2: // Case File
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: My word! That's horrible!" << endl << endl;
                    sleep_for(milliseconds(1000));
                    cout << "TONY: Just awful." << endl << endl;
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Please, do keep me updated on everything about this. I'd *hate* for the cows to not get justice." << endl << endl;
                    enter();
                    break;
                case 3: // Fur
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Gosh. I'd hate to be the poor fellow who lost all that. Must've been a real clumsy one." << endl << endl;
                    sleep_for(milliseconds(1000));
                    cout << "BLACKWOOD: Totts." << endl;
                    sleep_for(milliseconds(1000));
                    cout << "BLACKWOOD: There's no need to show the Mayor that." << endl << endl;
                    enter();
                    break;
                case 4: // Mustache
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Haha! It is NOTHING like mine!" << endl;
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Not at all..." << endl << endl;
                    enter();
                    break;
                case 5: // Stripes
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Scoundrel..." << endl;
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Has he been caught?" << endl << endl;
                    if(stripesArrested){
                        sleep_for(milliseconds(1000));
                        cout << "TONY: Found him myself, sir!" << endl << endl;
                        sleep_for(milliseconds(1000));
                        cout << "MAYOR: Very unfortunate for him..." << endl;
                        sleep_for(milliseconds(1000));
                        cout << "MAYOR: Good job detective!" << endl << endl;
                    }else{
                        sleep_for(milliseconds(1000));
                        cout << "TONY: Unfortunately not, sir..." << endl << endl;
                        sleep_for(milliseconds(1000));
                        cout << "MAYOR: I see. That's... worrying." << endl << endl;
                        sleep_for(milliseconds(1000));
                        cout << "BLACKWOOD: ..." << endl << endl;
                    }
                    enter();
                    break;
                case 6: // Cheese
                    sleep_for(milliseconds(1000));
                    cout << "The Mayor's eyes lit up, as if waiting for this moment. He didn't even have to take a bite." << endl << endl;
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Why, this is goat cheese. Gruff's Goat Milk Galore's goat cheese, to be exact. Undeniably so." << endl << endl;
                    sleep_for(milliseconds(1000));
                    enter();

                    you.updateInfo(allEvidence[4][0], "A beautiful slice of silky cheese... \nYummy, AND undeniably Gruff's goat cheese, according to the Mayor.");
                    you.viewEvidence(choice);
                    sleep_for(milliseconds(1000));
                    enter();

                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: My, surely Gruff wouldn't *brrrribe* someone to take down the cow milk industry!" << endl;
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: That would be simply preposterous." << endl << endl;
                    sleep_for(milliseconds(1000));
                    cout << "BLACKWOOD: We can't say either way, Mr. Mayor, but we will look into it." << endl << endl;
                    sleep_for(milliseconds(1000));
                    cout << "MAYOR: Excellent." << endl << endl;
                    enter();
                    scene = false;
                    break;
                case 7: // Mayor
                        if(!showMayor){
                            sleep_for(milliseconds(1000));
                            cout << "MAYOR: My! That is me! I sure do hope you don't suspect me of anything! Haha!" << endl << endl;
                            sleep_for(milliseconds(1000));
                            cout << "CHOICES:" << endl;
                            cout << "    1. \"You know what, I think I do!\"" << endl;
                            cout << "    2. \"No, of course not! Haha!\"" << endl;
                            cout << "Enter choice: ";
                            string input;
                            int secondChoice = -1;
                            getline(cin, input);
                            choice = validateAnswer(input, 2, 1);
                            while(choice == -1){
                                cout << "Try again: ";
                                getline(cin, input);
                                choice = validateAnswer(input, 2, 1);
                            }
                            switch(secondChoice){
                                case 1:
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: You know what! I think I do suspect you!" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "MAYOR: With no evidence? This is outrageous!" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BLACKWOOD: Totts. That's a demerit. To the Mayor? Really?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    strikeOut = you.wompWomp();
                                    accuseMayorEarly = true;
                                    break;
                                case 2:
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: No, of course not! Haha!" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "MAYOR: Haha!" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    break;
                            }
                        }else if(!accuseMayorEarly){
                            sleep_for(milliseconds(1000));
                            cout << "MAYOR: Yes, that is me again. Haha.. ha!" << endl << endl;
                            sleep_for(milliseconds(1000));
                        }else{
                            sleep_for(milliseconds(1000));
                            cout << "MAYOR: ..." << endl << endl;
                            sleep_for(milliseconds(1000));
                            cout << "TONY: ... I--" << endl << endl;
                            sleep_for(milliseconds(1000));
                            cout << "BLACKWOOD: I apologize for his behavior." << endl << endl;
                            sleep_for(milliseconds(1000));
                        }
                        enter();
                        break;
            }
            sleep_for(milliseconds(1000));
            if(!scene && !strikeOut){
                int evidence = you.addEvidence(allEvidence[6][0], allEvidence[6][1]);
                you.viewEvidence(evidence);
            }
            sleep_for(milliseconds(1000));
            enter();
        }
    }
    
    bool accusedGruff = false, closeCase = false;
    if(!strikeOut){
        // Goat's Gruff //
        rideToGruffs();
        scene = true;
        choice1 = false, choice2 = false, choice3 = false;
        bool discoveredEthnyan = false;
        while(scene){
            int numChoices = 2;
            cout << "Choices:" << endl;
            cout << "    1. [View inventory]" << endl;
            cout << "    2. [Inspect perimeter]" << endl;
            if(choice1){
                numChoices = 4;
                cout << "    3. [Enter Gruff's office]" << endl;
                cout << "    4. [Check the main factory]" << endl;
            }
            if(closeCase){
                numChoices = 5;
                cout << "    5. [Go to the Mayor's office (ENDS GAME)]" << endl;
            }
            cout << "Enter choice: ";
            string input;
            int choice = -1;
            getline(cin, input);
            choice = validateAnswer(input, numChoices, 1);
            while(choice == -1){
                cout << "Try again: ";
                getline(cin, input);
                choice = validateAnswer(input, numChoices, 1);
            }
            cout << endl;
            int evidence;
            bool innerScene;
            switch(choice){
                case 1:
                    viewInventory(you, true);
                    enter();
                    break;
                case 2:
                    if(!choice1){
                        sleep_for(milliseconds(1000));
                        cout << "TONY: Well, okay. We got ourselves Gruff's office, and it doesn't look like he's in there right now." << endl;
                        sleep_for(milliseconds(1000));
                        cout << "TONY: Then we got ourselves the main factory. Seems to be a lot of commotion in there." << endl;
                        sleep_for(milliseconds(1000));
                        cout << "TONY: Oh, I can see why. Detective, take a look at this." << endl << endl;
                        sleep_for(milliseconds(1000));
                        enter();

                        evidence = you.addEvidence(allEvidence[7][0], allEvidence[7][0]);
                        you.viewEvidence(evidence);
                        enter();

                        sleep_for(milliseconds(1000));
                        cout << endl << "BLACKWOOD: It looks like someone was eager to get in. The glass falls into the factory, so nothing inconsistent there." << endl << endl;
                        sleep_for(milliseconds(1000));
                        choice1 = true;
                        enter();
                    }else{
                        sleep_for(milliseconds(1000));
                        cout << "Two rooms, one of which has a broken window. Nothing new here." << endl << endl;
                        sleep_for(milliseconds(1000));
                        enter();
                    }
                    break;
                case 3:
                    if(!choice2){
                        sleep_for(milliseconds(1000));
                        cout << "TONY: It feels strange going in here without making ourselves known." << endl << endl;
                        sleep_for(milliseconds(1000));
                        cout << "BLACKWOOD: You'll get used to it." << endl << endl;
                        sleep_for(milliseconds(1000));
                        cout << "TONY: Is this legal?" << endl << endl;
                        sleep_for(milliseconds(1000));
                        cout << "BLACKWOOD: ..." << endl;
                        sleep_for(milliseconds(1000));
                        cout << "BLACKWOOD: Get a look at this." << endl << endl;
                        sleep_for(milliseconds(1000));
                        enter();

                        evidence = you.addEvidence(allEvidence[9][0], allEvidence[9][0]);
                        you.viewEvidence(evidence);
                        enter();

                        sleep_for(milliseconds(1000));
                        cout << "TONY: You didn't answer-- Nevermind. Anyways, it looks like Gruff had everything to gain from the milk industry collapsing." << endl << endl;
                        sleep_for(milliseconds(1000));
                        cout << "BLACKWOOD: You can't blame a man trying for rooting for his business." << endl;
                        sleep_for(milliseconds(1000));
                        cout << "BLACKWOOD: But it also looks like he was worried about something." << endl << endl;
                        sleep_for(milliseconds(1000));
                        enter();

                        evidence = you.addEvidence(allEvidence[10][0], allEvidence[10][0]);
                        you.viewEvidence(evidence);
                        enter();

                        sleep_for(milliseconds(1000));
                        cout << "TONY: So it looks like there could be someone else who wants in on this business..." << endl << endl;
                        sleep_for(milliseconds(1000));
                    }else{
                        sleep_for(milliseconds(1000));
                        cout << "Man. All the detectives know that it must either be Gruff or someone with something to gain from Gruff getting arrested." << endl << endl;
                        sleep_for(milliseconds(1000));
                    }
                    enter();
                    break;
                case 4:
                    if(!choice2){
                        gruffIntro();

                        evidence = you.addEvidence(allEvidence[8][0], allEvidence[8][0]);
                        you.viewEvidence(evidence);
                        enter();
                    }
                    innerScene = true;
                    while(innerScene){
                        cout << "Choices:" << endl;
                        cout << "    1. [View inventory]" << endl;
                        cout << "    2. [Ask Billy about an item]" << endl;
                        if(discoveredEthnyan && choice3){
                            cout << "    3. [REALLY squint at the picture on the wall]" << endl;
                        }else{
                            cout << "    3. [Observe the picture on the wall]" << endl;
                        }
                        cout << "    4. [Accuse Billy (ENDS GAME)]" << endl;
                        cout << "    5. [Go back outside]" << endl;
                        cout << "Enter choice: ";
                        string input;
                        int choice = -1;
                        getline(cin, input);
                        choice = validateAnswer(input, 5, 1);
                        while(choice == -1){
                            cout << "Try again: ";
                            getline(cin, input);
                            choice = validateAnswer(input, 5, 1);
                        }
                        cout << endl;
                        string askedAbout;
                        switch(choice){
                            case 1:
                                viewInventory(you, true);
                                enter();
                                break;
                            case 2:
                                evidence = viewInventory(you, false);
                                askedAbout = you.getNameForCheck(evidence);
                                if(askedAbout == allEvidence[4][0]){ // Cheese
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: That's my cheese alright." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Well, your cheese was paid to a man who committed another crime." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: And?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Do you know who could've given it to him?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: ... Buddy." << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: I had a thief break in last night. Maybe they did it. But even if they didn't, I sell to chains." << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: BIG stores." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: Any Joe Schmoe could've bought and given him that cheese." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: Although..." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: That's too fresh to not be the cheese stolen last night." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(askedAbout == allEvidence[6][0] || askedAbout == allEvidence[7][0]){ // Business info or broken window
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: I grew this business from the ground up. Independently and e'rything." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Congratulations, sir." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: It hurts to see the ole factory end up like this. Seein' someone wants to take it down." << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: It's got us goats nervous. But we've toughed it out through worse." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(askedAbout == allEvidence[3][0]){ // Stripes profile
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: I ain't never seen that feller in my life." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Yeah, he's not a good guy." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: Good guys are hard to come by nowadays. I hope you two are sensible." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(askedAbout == allEvidence[8][0]){ // Gruff profile
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: That's me alright." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Mhm." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: What? Expected me to say more than that?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(askedAbout == allEvidence[9][0]){ // Cow graph
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: What kind of business owner would I be if I ain't monitor the competition?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: This could be motive for you to commit the ongoing crime." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: Just because I want my goat milk to beat the cows ain't mean I'd disrespect them." << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: That's just barbaric." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(askedAbout == allEvidence[10][0]){ // Decree
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: This is part of what's getting me nervous." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Why?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: There's this feller on the portrait on the wall. We started the business together. I can tell you more about him after you get a look." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(askedAbout == allEvidence[11][0]){ // Associate info
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: It's been so long, y'know?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: I'm sure." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: And he's probably just out there waiting to get me." << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: It's awful." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(askedAbout == allEvidence[12][0]){ // Associate pic
                                    if(!choice3){
                                        sleep_for(milliseconds(1000));
                                        cout << "BILLY: Ah, Ethnyan." << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "TONY: Ethnyan, huh?." << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "BILLY: Yeah. The guy was taking money right out of my pocket." << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "BILLY: So, one day, I got him up and arrested." << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "BILLY: I never did fire him though. And with this talk of another crime, I'm starting to think he wants me gone." << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "BILLY: And I can't fire him, thanks to legal tomfoolery." << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "(And plot convenience, one might say!)" << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "BILLY: I'm just hoping you can catch him." << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "TONY: We can certainly try!" << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        enter();

                                        evidence = you.addEvidence(allEvidence[11][0], allEvidence[11][1]);
                                        you.viewEvidence(evidence);
                                        enter();
                                        choice3 = true;

                                        sleep_for(milliseconds(1000));
                                        cout << "TONY: Heh, Ethnyan sounds a lot like the Mayor's name, eh?" << endl << endl;
                                        sleep_for(milliseconds(1000));
                                    }else{
                                        cout << "BILLY: I told you e'rything I could 'bout Ethnyan." << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "BILLY: I'm just hoping you can catch him." << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        cout << "BLACKSTONE: We will certainly try." << endl << endl;
                                        sleep_for(milliseconds(1000));
                                        enter();
                                        sleep_for(milliseconds(1000));
                                        cout << "TONY: Heh, Ethnyan sounds a lot like the Mayor's name, eh?" << endl << endl;
                                        sleep_for(milliseconds(1000));
                                    }
                                }else{
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: What's this gotta do with me?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: ... Nothing, sir." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BILLY: Better be nothing. We got a thief on the loose here." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }
                                enter();
                                break;
                            case 3:
                                if(!discoveredEthnyan){
                                    sleep_for(milliseconds(1000));
                                    cout << "Tony found himself staring at the picture of the wall. It was Billy standing with a scraggly white cat." << endl;
                                    cout << "Considering the placement of the portrait, they were probably cofounders." << endl;
                                    cout << "In the corner, it's signed by Gruff and a man named Ethnyan." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: That Ethnyan guy is probably out of the picture now, huh?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    enter();

                                    discoveredEthnyan = true;
                                    evidence = you.addEvidence(allEvidence[12][0], allEvidence[12][1]);
                                    you.viewEvidence(evidence);
                                }else if(!choice3){
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Man, I wonder if Mr. Gruff could tell me anything about this guy." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else if(closeCase){
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: I can't believe the Mayor is a bad guy..." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                }else{
                                    sleep_for(milliseconds(1000));
                                    cout << "Tony found himself staring at the picture of the wall again." << endl;
                                    cout << "He squinted at the white cat." << endl;
                                    cout << "It almost seemed to squint back" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: The Mayor's name is a LOT like Ethnyan." << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: And he does have white fur..." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "Tony reached into his pocket, and he grabbed the fake mustache." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: Blackwood..." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "Blackwood walked over, looking at Tony." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BLACKWOOD: Hm...?" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "TONY: The Mayor is Ethnyan. Look." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BLACKWOOD: There's no way--" << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "The two looked at the picture with the mustache." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BLACKWOOD: Congratulations, Totts." << endl;
                                    sleep_for(milliseconds(1000));
                                    cout << "BLACKWOOD: I think you just made your whole career." << endl << endl;
                                    sleep_for(milliseconds(1000));
                                    you.removeEvidence(allEvidence[2][0]);
                                    you.updateInfo(allEvidence[12][0],"A young Billy with a young Ethnyan, now including a mustache!");
                                    closeCase = true;
                                }
                                enter();
                                break;
                            case 4:
                                accusedGruff = true;
                                sleep_for(milliseconds(1000));
                                cout << "TONY: Mr. Billy G. Gruffman, you are under arrest." << endl << endl;
                                sleep_for(milliseconds(1000));
                                cout << "BILLY: Huh? I thought you were here to help me!" << endl << endl;
                                sleep_for(milliseconds(1000));
                                cout << "TONY: Unfortunately, ample evidence points towards you being responsible to the crime." << endl << endl;
                                sleep_for(milliseconds(1000));
                                cout << "BILLY: I can't believe this! I need a lawyer, you hear? A lawyer!" << endl << endl;
                                sleep_for(milliseconds(1000));
                                cout << "TONY: Of course, Mr. Gruff. Now, police are on the way in the meantime." << endl << endl;
                                sleep_for(milliseconds(1000));
                                cout << "BLACKWOOD: Good job closing up your first case, kid." << endl << endl;
                                sleep_for(milliseconds(1000));
                                enter();
                                innerScene = false;
                                scene = false;
                                break;
                            case 5:
                                innerScene = false;
                                break;
                        }
                    }
                    break;
                case 5:
                    scene = false;
                    break;
            }
        }

        // Arrest the Mayor //
        if(closeCase && !accusedGruff){
            sleep_for(milliseconds(1000));
            cout << "BLACKWOOD: This is completely insane, but I have your back." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "TONY: I just can't believe he's lied to us about everything. He lied about being a good guy. He lied about his MUSTACHE!" << endl << endl;
            sleep_for(milliseconds(1000)); 
            enter();
            sleep_for(milliseconds(1000)); 
            cout << "The two detectives burst through the golden doors and into the Mayor's sparkling office-space, where they find their feline Mayor sampling a wheel of asiago." << endl;
            cout << "He stands to his feet, surprised and angered by this egregious and unwarranted aggression towards his dazzling aperture." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "MAYOR: Now I say now I say! Gentlemen! What the devil is the matter with you two? I almost spit out my asiago--it's fresh from I-TALLY." << endl;
            sleep_for(milliseconds(1000));
            cout << "MAYOR: There best be a reason for such an untimely and rude intrusion!" << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "BLACKWOOD: I think you know why we're here sir." << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "TONY: Yeah, Mr. Mayor... Or, should I say MR. MAYOR! ... WHO ALSO HAPPENS TO ALSO BE A CRIMINAL!" << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "The Mayor's brow furls, his paws begin to sweat, but otherwise seems to be unbothered. " << endl;
            cout << "His demeanor changes, his bowler hat, knocked ajar by the detective's startling entry, has been adjusted to be firmly atop his head. The Mayor stands tall." << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "MAYOR: Harumph I say! What a dastardly accusation! I'll have you both stripped of your badges and run out of town for such a statement!" << endl;
            sleep_for(milliseconds(1000));
            cout << "TONY: I can't speak much on your whiskers, but your mustache, huh?" << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "MAYOR: What about it? Are you going to belittle my mighty and proud features next sir? Have you sunk to something as low as common insults? " << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "TONY: I don't like this either, Mr. Mayor Who Happens To Also Be a Criminal." << endl;
            sleep_for(milliseconds(1000)); 
            cout << "TONY: I don't like this because you've fooled the fine people of this city into believing that the gorgeous mustache above your lip is genuine!" << endl;
            sleep_for(milliseconds(1000)); 
            cout << "TONY: Take it off at once you scoundrel I will absolutely not stand for this blatant injustice!" << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "BLACKWOOD: Totts, let's relax..." << endl;
            sleep_for(milliseconds(1000)); 
            cout << "BLACKWOOD: We're here for an arrest not a persecution..." << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "TONY: Right! Sorry...!" << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "BLACKWOOD: Ahem. Mayor Ethan Langstrom, we have a warrant for your arrest. Theft. Defamation. Tax evasion (probably)--" << endl << endl;
            sleep_for(milliseconds(500)); 
            cout << "TONY: --And being a lying jerk. (We don't have a warrant???)--" << endl << endl;
            sleep_for(milliseconds(500)); 
            cout << "BLACKWOOD: --Most importanly, though, wastage of our fine dairy, you'd think somebody like you would understand the importance of our dairy." << endl;
            sleep_for(milliseconds(1000)); 
            cout << "BLACKWOOD: Take the mustache off before you force our hands, scumbag. " << endl << endl;
            sleep_for(milliseconds(1000)); 
            enter();

            sleep_for(milliseconds(1000)); 
            cout << "A wave of panic washes over the Mayor for an instant, and then he collects himself, ripping off an obviously fake (actually no, not really obviously fake) mustache." << endl;
            cout << "His face looks barren, perhaps even shameful. A shell of the cat he once was. The motivation behind applying the hairy falsehood was apparent." << endl << endl;
            sleep_for(milliseconds(1000)); 
            enter();

            sleep_for(milliseconds(1000)); 
            cout << "MAYOR: Fine then, look upon me as I truly am! The way that I was truly designed!" << endl;
            sleep_for(milliseconds(1000)); 
            cout << "MAYOR: You think this will prove anything? Preposterous. Forget running you out of town, I'll have you two thrown in an asylum! " << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "BLACKWOOD: Detective Totts, call in for backup." << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "TONY: No need for calling! I just found out I have this button that does the job even faster!" << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "BLACKWOOD: You found a what--" << endl << endl;
            sleep_for(milliseconds(500));
            cout << "The scene turned chaotic. Hundreds of officers swarmed the building, seeping from every crevice." << endl;
            cout << "From the windows. From the flower vase. From the half-eaten wheel of asiago in the Mayor's hand. Even out of the fallen mustache. They were everywhere." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "BLACKWOOD: Good timing boys, glad those disguise classes the ICUP provided proved their worth. Take him!" << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "MAYOR: Come now gentleman, at least give a fellow a chance to run! This is downright uncivilized. Uncouth! Foolish!" << endl << endl;
            sleep_for(milliseconds(1000)); 
            cout << "TONY: The only thing uncouth is your bald faced lie Mr. Mayor. Wink!" << endl << endl;
            sleep_for(milliseconds(1000)); 
            enter();
        }
    }
    
    if(strikeOut){
        sleep_for(milliseconds(1000));
        cout << "[AT THE NOW GLOOMY AND SAD ICEBERG CITY URBAN PATROL HQ . . .]" << endl << endl;
        sleep_for(milliseconds(1000)); 
        cout << "Tony skulked over to Detective Corvus Blackwood's desk, head down in shame." << endl;
        cout << "He held back a sad puppy whimper as he placed his shiny new badge on the desk." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: I apologize, detective--" << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: You accused a victim, let a thief go when you had him right in front of you, and accused the Mayor, Totts." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "TONY: I understand." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: ..." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "BLACKWOOD: I'm sorry, Totts, but you're fired." << endl << endl;
        sleep_for(milliseconds(1000));
        enter();

        sleep_for(milliseconds(1000));
        cout << "Tony Totts later went on to start a true crime podcast." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "..." << endl << endl;
        sleep_for(milliseconds(1000));
        cout << "It's not very good." << endl << endl;
        sleep_for(milliseconds(1000));
        enter();
    }else{
        sleep_for(milliseconds(1000));
        cout << "After the conclusion of the investigation, the cows ended their strike, revitalizing the Iceberge City milk industry." << endl << endl;
        sleep_for(milliseconds(1000));
        if(stripesArrested){
            cout << "Stripes served time for all his crimes that he had managed to evade up until Tony sniffed right through him." << endl;
            sleep_for(milliseconds(1000));
            cout << "After his release, Tony referred Stripes to Gruff because Stripes loved Gruff's cheese so much." << endl;
            cout << "Stripes went on to become an excellent quality-inspector for Gruff's Goat Milk Galore." << endl << endl;
        }else{
            cout << "After Stripes' big escape, he moved on to bigger and bolder crimes." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Stripes is currently wanted for stealing the Mona Cheesa." << endl;
        }
        sleep_for(milliseconds(1000));
        if(accusedGruff){
            if(closeCase){
                cout << "Despite knowing fully that the Mayor did the crime..." << endl;
                sleep_for(milliseconds(1000));
            }
            cout << "The detective duo managed to cough up enough evidence that Gruff was responsible for the rotten crime." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Immediately, the crime streak came to an end." << endl;
            cout << "Suddenly, the Mayor stepped up, taking charge of Gruff's Goat Milk Galore." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Junior Detective Tony Totts was promoted to plain old Detective Tony Totts." << endl;
            cout << "He and Blackwood continued to work together." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Everyday, Totts receives a letter from Gruff telling him he's wrong." << endl << endl;
        }else{
            cout << "After the Mayor's arrest, the news was set ablaze with a hot topic: Who will be Mayor now?" << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Tony Totts was offered the role for his venerable discovery." << endl;
            if(accuseMayorEarly){
                cout << "... And his incredible forsight, considering he accused the Mayor so early on ..." << endl;
            }
            cout << endl;
            sleep_for(milliseconds(1000));
            cout << "Tony declined." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Afterwards, Corvus Blackwood was offered the role for his involvement in catching the wretched Ethnyan." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Blackwood declined." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Finally, Billy G. Gruffman was offered the role as compensation for the distress caused by Ethnyan's actions." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "Billy declined." << endl << endl;
            sleep_for(milliseconds(1000));
            cout << "The town has since opted to temporarily give the leader of the cow strike the position." << endl << endl;
        }
        sleep_for(milliseconds(1000));
        enter();
    }

    sleep_for(milliseconds(1000));
    cout << endl << endl << "T H E  E N D" << endl << endl;
    return 0;
}

void title(){
    cout << ".OOOOOOOOOOOOOOO  @@        T o n y  T o t t s        @@ OOOOOOOOOOOOOOOO." << endl;
    cout << "OOOOOOOOOOOOOOOO @@                                    @@ OOOOOOOOOOOOOOOO" << endl;
    cout << "OOOOOOOOOO'''''' @@                                    @@ ```````OOOOOOOOO" << endl;
    cout << "OOOOO'' aaa@@@@@@@@@@@@@@@@@@@@\"\"\"                   \"\"\"\"\"\"\"\"\"@@aaaa `OOOO" << endl;
    cout << "OOOOO,\"\"\"\"@@@@@@@@@@@@@@\"\"\"\"                                     a@\"\" OOOA" << endl;
    cout << "OOOOOOOOOooooooooo,                                       |OOo    ooOOOOOS" << endl;
    cout << "OOOOOOOOOOOOOOOOo,                                        |OOO      OOOOOC" << endl;
    cout << "OOOOOOOOOOOOOOOOOO   (     A Rotten Case of Milk       ,|OO         OOOI" << endl;
    cout << "OOOOOOOOOOOOOOOOOO    @        (You'll get it)          |OOO         OOOI" << endl;
    cout << "OOOOOOOOOOP      |                                      OOOO         OOOOb" << endl;
    cout << "OOOOOOOOOOO      |                                      |OO          OOOOOy" << endl;
    cout << "OOOOOOOOOOOOO ''                                        aa`OOO      OOOOP" << endl;
    cout << "OOOOOOOOOOOOOOb          w                                  `@aa``OOOOOOOh" << endl;
    cout << "OG art by OOOO) \\       w                                     `@@@aa OOOOo" << endl;
    cout << "Roy Sussman OOOO  wwwww                                     @@@ OOOOe" << endl;
    cout << "OOOOOOOOOOOOOOOO                                 aaaaaaa       @@',OOOOn" << endl;
    cout << "OOOOOOOOOOOOOOOO)                            aaa@@@@@@@@\"\"        @@ OOOOOi" << endl;
    cout << "OOOOOOOOOO~~ aaaaaa\"aaaaaa            aaa@@@@@@@@@@\"\"            @@ OOOOOx" << endl;
    cout << "OOOOOO aaaa@\"\"\"\"\"\"\"\" \"\"            @@@@@@@@@@@@\"\"               @@@|`OOOO'" << endl;
    cout << "OOOOOOOo`@@a                  aa@@  @@@@@@@\"\"         a@        @@@@ OOOO9" << endl;
    cout << "OOOOOOO'  `@@a               @@a@@   @@\"\"           a@@   a     |@@@ OOOO3" << endl;
    cout << "`OOOO'       `@    aa@@       aaa\"\"\"          @a        a@     a@@@',OOOO'" << endl;
    cout << endl << "                      (Press enter to start)                                 ";
    string temp;
    getline(cin, temp);
    cout << endl;
}

void intro(){
    sleep_for(milliseconds(1000));
    cout << "[AT ICEBERG CITY URBAN PATROL HQ . . .]" << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "Iceberg City is in danger... A lot of danger... It's economy... It's people..." << endl;
    cout << "A crime has caused a stir in the local cow population, who have gone on strike until the perpetrator is caught." << endl;
    cout << "The cows carry the city's economy on their udders. They will not have their work disrespected, and they will crash the economy if it comes to it." << endl;
    cout << "The fate of the city rests in the hands of two detectives..." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "Senior Detective Corvus Blackwood walked up to the office. His sharp beak shined menacingly in the doorway." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "BLACKWOOD: Congratulation, Totts. This is your first real case." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "He slid a folder onto Junior Detective Tony Totts' desk. He waited expectantly for the retriever to open it." << endl << endl;
    enter();
}

void rickysHouse(){
    sleep_for(milliseconds(1000));
    cout << "[AFTER A SILENT RIDE TO RICKY GREEN'S HOUSE . . .]" << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "The house was blocked off with crime scene tape. In the front yard is a crying chameleon. Mr. Ricky Green himself." << endl;
    cout << "He mourned the loss of his sweet, creamy milk. It's the only fair reaction." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "TONY: Mr. Green... I'm sorry for your loss, sir..." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "RICKY: It's alright... As long as you catch that sick freak..." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "BLACKWOOD: And we will, Mr. Green. My partner and I just gotta investigate the scene first. We'll avenge your carton." << endl << endl;
    enter();
}

void motelTicks(){
    sleep_for(milliseconds(1000));
    cout << "[AROUND THE CORNER, AT A MOTEL TICKS . . .]" << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "Tony Totts and Detective Blackwood knew exactly who was behind the sick deed. Tony himself could smell him in the air." << endl;
    cout << "They also knew exactly the motel he resided at." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "TONY: I can't believe he would do something like this..." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "BLACKWOOD: He's a scumbag. I wouldn't be surprised." << endl;
    sleep_for(milliseconds(1000));
    cout << "BLACKWOOD: Anyways, I'll do some looking around, and you check the room." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "Blackwood stepped away as Tony walked up to one of the motel doors and knocked." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "An unfamiliar, unrecognizable raccoon with a mustache stepped out." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "???: Mmph. Hello. I was just leaving." << endl << endl;
    enter();
}

void MayorIntro(){
    sleep_for(milliseconds(1000));
    cout << "[AFTER A PLEASANT STROLL TO THE MAYOR'S . . .]" << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "Blackwood and Tony made it to the front steps of town hall." << endl;
    cout << "They didn't have to consult any secretaries or attendants thanks to Blackwood's experience. Tony looked around nervously." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "TONY: You know, I've never met the Mayor." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "BLACKWOOD: Alright." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "TONY: Are we going to be bothering him?" << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "Blackwood knocked on the office door." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "BLACKWOOD: No, he's too nice for that." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "A fat white cat with an extremely elaborate mustache opened the door." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "MAYOR: Ah, Detective Blackwood! And..." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "TONY: Junior Detective Tony Totts." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "MAYOR: Of course! Pleasure to meet you, Detective Totts. Come inside." << endl << endl;
    enter();
}

void rideToGruffs(){
    sleep_for(milliseconds(1000));
    cout << "[ON THE RIDE TO GRUFF'S GOAT MILK GALORE . . .]" << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "BLACKWOOD: Alright. I can feel that we're getting closer to catching this sick bastard..." << endl;
    sleep_for(milliseconds(1000));
    cout << "BLACKWOOD: It could all end here. You just need to gather evidence. Then, badabing, your first big case is closed. " << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "TONY: Wowza. Okay. No pressure, Tony. You got this." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "BLACKWOOD: No, all the pressure. The stability of this whole town rests on your shoulders. The cows and Mayor are relying on you." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "TONY: ..." << endl;
    sleep_for(milliseconds(1000)); 
    cout << "TONY: Right." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "BLACKWOOD: Now is no time for funny business. Lock in, Totts." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "The detectives rolled to a stop in front of the large factory." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "TONY: Alright, let's finish this." << endl << endl;
    sleep_for(milliseconds(1000));
    enter();
}

void gruffIntro(){
    sleep_for(milliseconds(1000));
    cout << "The two detectives walked into the main factory, and they were met with a nervous older goat." << endl;
    cout << "He paced the room, talking to all the employees. That had to be the Gruff of Gruff's Goat Milk Galore." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "BLACKWOOD: Mr. Gruff! We're detectives with the ICUP--" << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "BILLY: Oh, thank god! I ain't think anyone called the police, but I'm glad yer here." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "TONY: ... Well--" << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "BLACKWOOD: Of course, Mr. Gruff." << endl << endl;
    sleep_for(milliseconds(1000));
    cout << "BILLY: Just Billy is fine." << endl << endl;
    sleep_for(milliseconds(1000)); 
    cout << "TONY: Sure thing, Billy. We'll just start investigating now." << endl << endl;
    sleep_for(milliseconds(1000));
    enter();
}

void enter(){
    cout << "(Press enter to continue)";
    string temp;
    getline(cin, temp);
    cout << endl;
}

int validateAnswer(string answer, int highest, int lowest){
    if(!isdigit(answer[0]) || answer.length()>2){
        return -1;
    }else if(stoi(answer) > highest || stoi(answer) < lowest){
        return -1;
    }
    return stoi(answer);
}

int viewInventory(TonyTotts& you, bool includeExit){
    int lowest = 1;
    you.viewList();
    if(includeExit){
        cout << "    0. Exit" << endl;
        lowest = 0;
    }

    cout << "Enter choice: ";
    string input;
    int choice = -1;
    getline(cin, input);
    choice = validateAnswer(input, you.getNumEvidence(), lowest);
    while(choice == -1){
        cout << "Try again: ";
        getline(cin, input);
        choice = validateAnswer(input, you.getNumEvidence(), lowest);
    }
    if(choice != 0){
        you.viewEvidence(choice);
    }else{
        cout << endl;
    }
    
    return choice;
}

// updatedEvidence[] = {
//     "Billy's fancy business decree. \nIf he gets into a position where he could not manage the company, the next authority figure of the company gets power. \nIf Ethnyan is out there... it's him.",
// }