#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

static const std::vector<std::string> main_wpns = {"Axe", "Dagger", "Mace", "Pistol", "Sword", "Scepter"};

static const std::vector<std::string> professions = {"Guardian", "Revenant", "Warrior", "Engineer", "Ranger", "Thief", "Elementalist", "Mesmer", "Necromancer"};

static const std::vector<std::string> guard_specializations = {"Zeal", "Radiance", "Valor", "Honor", "Virtues",
                                                               "Dragonhunter", "Firebrand", "Willbender"};


static const std::vector<std::vector<string>> zeal_traits = {{"Wrathful Spirit", "Fiery Wrath", "Zealous Scepter"},
                                                             {"Furious Focus", "Zealous Blade", "Kindled Zeal"},
                                                             {"Eternal Armory", "Shattered Aegis", "Symbolic Avenger"}};
static const std::vector<std::vector<string>> radiance_traits = {{"Inner Fire", "Right-Hand Strength", "Healer's Resolution"},
                                                                 {"Wrath of Justice", "Radiant Fire", "Retribution"},
                                                                 {"Amplified Wrath", "Perfect Inscriptions", "Righteous Instincts"}};
static const std::vector<std::vector<string>> valor_traits = {{"Strength of the Fallen", "Smiter's Boon", "Focus Mastery"},
                                                              {"Stalwart Defender", "Strength in Numbers", "Communal Defenses"},
                                                              {"Altruistic Healing", "Monk's Focus", "Tenacious Defense"}};
static const std::vector<std::vector<string>> honor_traits = {{"Invigorated Bulwark", "Protective Reviver", "Protector's Restoration"},
                                                              {"Honorable Staff", "Pure of Heart", "Empowering Might"},
                                                              {"Pure of Voice", "Writ of Persistence", "Force of Will"}};
static const std::vector<std::vector<string>> virtues_traits = {{"Unscathed Contender", "Resolute Subconscious", "Master of Consecrations"},
                                                                {"Inspiring Virtue", "Absolute Resolve", "Glacial Heart"},
                                                                {"Permeating Wrath", "Battle Presence", "Indomitable Courage"}};
static const std::vector<std::vector<string>> dragonhunter_traits = {{"Piercing Light", "Dulled Senses", "Soaring Devastation"},
                                                                     {"Hunter's Determination", "Zealot's Aggression", "Bulwark"},
                                                                     {"Hunter's Fortification", "Heavy Light", "Big Game Hunter"}};
static const std::vector<std::vector<string>> firebrand_traits = {{"Unrelenting Criticism", "Liberator's Vow", "Archivist of Whispers"},
                                                                  {"Weighty Terms", "Stalwart Speed", "Legendary Lore"},
                                                                  {"Stoic Demeanor", "Quickfire", "Loremaster"}};
static const std::vector<std::vector<string>> willbender_traits = {{"Searing Pact", "Power for Power", "Conceited Curate"},
                                                                   {"Restorative Virtues", "Holy Reckoning", "Vanguard Tactics"},
                                                                   {"Phoenix Protocol", "Tyrant's Momentum", "Deathless Courage"}};


static const std::vector<std::vector<string>> guard_healskills = {{"Receive the Light!", "Litany of Wrath", "Shelter", "Signet of Resolve"},
                                                                  {"Receive the Light!", "Litany of Wrath", "Shelter", "Signet of Resolve", "Purification"},
                                                                  {"Receive the Light!", "Litany of Wrath", "Shelter", "Signet of Resolve", "Mantra of Solace"},
                                                                  {"Receive the Light!", "Litany of Wrath", "Shelter", "Signet of Resolve", "Reversal of Fortune"}};
static const std::vector<std::vector<string>> guard_utilityskills = {{"Hallowed Ground", "Purging Flames", "Sanctuary", "Wall of Reflection", "Contemplation of Purity", "Judge's Intervention", "Merciful Intervention", "Smite Condition", "Hold the Line!", "Advance!", "Save Yourselves!", "Stand Your Ground!", "Bane Signet", "Signet of Judgement", "Signet of Mercy", "Signet of Wrath", "Bow of Truth", "Hammer of Wisdom", "Shield of the Avenger", "Sword of Justice"},
                                                                     {"Hallowed Ground", "Purging Flames", "Sanctuary", "Wall of Reflection", "Contemplation of Purity", "Judge's Intervention", "Merciful Intervention", "Smite Condition", "Hold the Line!", "Advance!", "Save Yourselves!", "Stand Your Ground!", "Bane Signet", "Signet of Judgement", "Signet of Mercy", "Signet of Wrath", "Bow of Truth", "Hammer of Wisdom", "Shield of the Avenger", "Sword of Justice", "Fragments of Faith", "Light's Judgement", "Test of Faith", "Procession of Blades"},
                                                                     {"Hallowed Ground", "Purging Flames", "Sanctuary", "Wall of Reflection", "Contemplation of Purity", "Judge's Intervention", "Merciful Intervention", "Smite Condition", "Hold the Line!", "Advance!", "Save Yourselves!", "Stand Your Ground!", "Bane Signet", "Signet of Judgement", "Signet of Mercy", "Signet of Wrath", "Bow of Truth", "Hammer of Wisdom", "Shield of the Avenger", "Sword of Justice", "Mantra of Flame", "Mantra of Lore", "Mantra of Truth", "Mantra of Potence"},
                                                                     {"Hallowed Ground", "Purging Flames", "Sanctuary", "Wall of Reflection", "Contemplation of Purity", "Judge's Intervention", "Merciful Intervention", "Smite Condition", "Hold the Line!", "Advance!", "Save Yourselves!", "Stand Your Ground!", "Bane Signet", "Signet of Judgement", "Signet of Mercy", "Signet of Wrath", "Bow of Truth", "Hammer of Wisdom", "Shield of the Avenger", "Sword of Justice", "Flash Combo", "Whirling Light", "Heel Crack", "Roiling Light"}};
static const std::vector<std::vector<string>> guard_eliteskills = {{"Feel My Wrath!", "Renewed Focus", "Signet of Courage"},
                                                                   {"Feel My Wrath!", "Renewed Focus", "Signet of Courage", "Dragon's Maw"},
                                                                   {"Feel My Wrath!", "Renewed Focus", "Signet of Courage", "Mantra of Liberation"},
                                                                   {"Feel My Wrath!", "Renewed Focus", "Signet of Courage", "Heaven's Palm"}};


static const std::vector<std::vector<string>> guard_weapons = {{"Greatsword", "Hammer", "Staff", "Mace", "Scepter", "Sword"},
                                                               {"Greatsword", "Hammer", "Staff", "Mace", "Scepter", "Sword", "Longbow"},
                                                               {"Greatsword", "Hammer", "Staff", "Mace", "Scepter", "Sword", "Axe"},
                                                               {"Greatsword", "Hammer", "Staff", "Mace", "Scepter", "Sword"}};
static const std::vector<std::vector<string>> guard_offweapons = {{"Focus", "Shield", "Torch"},
                                                                  {"Focus", "Shield", "Torch"},
                                                                  {"Focus", "Shield", "Torch"},
                                                                  {"Focus", "Shield", "Torch", "Sword"}};


static const std::vector<std::string> rev_specializations = {"Corruption", "Retribution", "Salvation", "Invocation", "Devastation",
                                                             "Herald", "Renegade", "Vindicator"};


static const std::vector<std::vector<string>> corruption_traits = {{"Acolyte of Torment", "Demonic Defiance", "Replenishing Despair"},
                                                                   {"Abyssal Chill", "Demonic Resistance", "Pact of Pain"},
                                                                   {"Diabolic Inferno", "Fiendish Tenacity", "Permeating Pestilence"}};
static const std::vector<std::vector<string>> retribution_traits = {{"Planar Protection", "Close Quarters", "Spiritual Resolution"},
                                                                    {"Eye for an Eye", "Resolute Evasion", "Dwarven Battle Training"},
                                                                    {"Vicious Reprisal", "Versed in Stone", "Steadfast Rejuvenation"}};
static const std::vector<std::vector<string>> salvation_traits = {{"Vital Blessing", "Blinding Truths", "Tranquil Balance"},
                                                                  {"Words of Censure", "Resilient Spirit", "Invoking Harmony"},
                                                                  {"Generous Abundance", "Unyielding Devotion", "Selfless Amplification"}};
static const std::vector<std::vector<string>> invocation_traits = {{"Cleansing Channel", "Rising Tide", "Glaring Resolve"},
                                                                   {"Spirit Boon", "Rapid Flow", "Incensed Response"},
                                                                   {"Song of the Mists", "Charged Mists", "Roiling Mists"}};
static const std::vector<std::vector<string>> devastation_traits = {{"Aggressive Agility", "Unsuspecting Strikes", "Battle Scarred"},
                                                                    {"Assassin's Presence", "Notoriety", "Thrill of Combat"},
                                                                    {"Brutality", "Swift Termination", "Dance of Death"}};
static const std::vector<std::vector<string>> herald_traits = {{"Elder's Respite", "Core Value", "Rising Momentum"},
                                                               {"Shared Empowerment", "Shining Aspects", "Hardening Persistence"},
                                                               {"Elevated Compassion", "Draconic Echo", "Forceful Persistence"}};
static const std::vector<std::vector<string>> renegade_traits = {{"Ashen Demeanor", "Blood Fury", "Wrought-Iron Will"},
                                                                 {"Bold Reversal", "Heartpiercer", "All for One"},
                                                                 {"Vindication", "Lasting Legacy", "Righteous Rebel"}};
static const std::vector<std::vector<string>> vindicator_traits = {{"Leviathan Strength", "Amnesty of Shing Jea", "Redemptor's Sermon"},
                                                                   {"Reaver's Curse", "Angsiyan's Trust", "Song of Arboreum"},
                                                                   {"Forerunner of Death", "Vassals of the Empire", "Saint of zu Heltzer"}};


static const std::vector<std::vector<string>> rev_legends = {{"Legendary Assassin Stance", "Legendary Demon Stance", "Legendary Dwarf Stance", "Legendary Centaur Stance"},
                                                             {"Legendary Assassin Stance", "Legendary Demon Stance", "Legendary Dwarf Stance", "Legendary Centaur Stance", "Legendary Dragon Stance"},
                                                             {"Legendary Assassin Stance", "Legendary Demon Stance", "Legendary Dwarf Stance", "Legendary Centaur Stance", "Legendary Renegade Stance"},
                                                             {"Legendary Assassin Stance", "Legendary Demon Stance", "Legendary Dwarf Stance", "Legendary Centaur Stance", "Legendary Alliance Stance"}};


static const std::vector<std::vector<string>> rev_weapons = {{"Mace", "Sword", "Hammer", "Staff"},
                                                             {"Mace", "Sword", "Hammer", "Staff"},
                                                             {"Mace", "Sword", "Hammer", "Staff", "Shortbow"},
                                                             {"Mace", "Sword", "Hammer", "Staff", "Greatsword"}};
static const std::vector<std::vector<string>> rev_offweapons = {{"Axe", "Sword"},
                                                                {"Axe", "Sword", "Shield"},
                                                                {"Axe", "Sword"},
                                                                {"Axe", "Sword"}};


static const std::vector<std::string> war_specializations = {"Strength", "Arms", "Defense", "Tactics", "Discipline",
                                                             "Berserker", "Spellbreaker", "Bladesworn"};


static const std::vector<std::vector<string>> strength_traits = {{"Brave Stride", "Restorative Strength", "Peak Performance"},
                                                                 {"Body Blow", "Forceful Greatsword", "Great Fortitude"},
                                                                 {"Berserker's Power", "Might Makes Right", "Merciless Hammer"}};
static const std::vector<std::vector<string>> arms_traits = {{"Wounding Precision", "Signet Mastery", "Opportunist"},
                                                             {"Unsuspecting Foe", "Sundering Burst", "Blademaster"},
                                                             {"Burst Precision", "Furious", "Dual Wielding"}};
static const std::vector<std::vector<string>> defense_traits = {{"Shield Master", "Dogged March", "Cull the Weak"},
                                                                {"Defy Pain", "Armored Attack", "Sundering Mace"},
                                                                {"Hardened Armor", "Last Stand", "Cleansing Ire"}};
static const std::vector<std::vector<string>> tactics_traits = {{"Leg Specialist", "Soldier's Comfort", "Roaring Reveille"},
                                                                {"Warrior's Cunning", "Shrug It Off", "Empower Allies"},
                                                                {"Martial Cadence", "Vigorous Shouts", "Phalanx Strength"}};
static const std::vector<std::vector<string>> discipline_traits = {{"Crack Shot", "Warrior's Sprint", "Vengeful Return"},
                                                                   {"Doubled Standards", "Destruction of the Empowered", "Brawler's Recover"},
                                                                   {"Axe Mastery", "Heightened Focus", "Burst Mastery"}};
static const std::vector<std::vector<string>> berserker_traits = {{"Smash Brawler", "Last Blaze", "Savage Instinct"},
                                                                  {"Blood Reaction", "Heat the Soul", "Dead or Alive"},
                                                                  {"Bloody Roar", "King of Fires", "Eternal Champion"}};
static const std::vector<std::vector<string>> spellbraker_traits = {{"Pure Strike", "Guard Counter", "No Escape"},
                                                                    {"Loss Aversion", "Slow Counter", "Sun and Moon Style"},
                                                                    {"Enchantment Collapse", "Revenge Counter", "Magebane Tether"}};
static const std::vector<std::vector<string>> bladesworn_traits = {{"River's Flow", "Swift as the Wind", "Unseen Sword"},
                                                                   {"Unshakable Mountain", "Fierce as Fire", "Lush Forest"},
                                                                   {"Immortal Dragon", "Unyielding Dragon", "Daring Dragon"}};


static const std::vector<std::vector<string>> war_healskills = {{"Mending", "To the Limit!", "Healing Signet", "Defiant Stance"},
                                                                {"Mending", "To the Limit!", "Healing Signet", "Defiant Stance", "Blood Reckoning"},
                                                                {"Mending", "To the Limit!", "Healing Signet", "Defiant Stance", "Natural Healing"},
                                                                {"Mending", "To the Limit!", "Healing Signet", "Defiant Stance", "Combat Stimulant"}};
static const std::vector<std::vector<string>> war_utilityskills = {{"Banner of Defense", "Banner of Discipline", "Banner of Strength", "Banner of Tactics", "Bull's Charge", "Kick", "Stomp", "Throw Bolas", "Fear Me!", "For Great Justice!", "On My Mark!", "Shake it Off!", "Dolyak Signet", "Signet of Fury", "Signet of Might", "Signet of Stamina", "Balanced Stance", "Berserker Stance", "Endure Pain", "Frenzy"},
                                                                   {"Banner of Defense", "Banner of Discipline", "Banner of Strength", "Banner of Tactics", "Bull's Charge", "Kick", "Stomp", "Throw Bolas", "Fear Me!", "For Great Justice!", "On My Mark!", "Shake it Off!", "Dolyak Signet", "Signet of Fury", "Signet of Might", "Signet of Stamina", "Balanced Stance", "Berserker Stance", "Endure Pain", "Frenzy", "Outrage", "Shattering Blow", "Sundering Leap", "Wild Blow"},
                                                                   {"Banner of Defense", "Banner of Discipline", "Banner of Strength", "Banner of Tactics", "Bull's Charge", "Kick", "Stomp", "Throw Bolas", "Fear Me!", "For Great Justice!", "On My Mark!", "Shake it Off!", "Dolyak Signet", "Signet of Fury", "Signet of Might", "Signet of Stamina", "Balanced Stance", "Berserker Stance", "Endure Pain", "Frenzy", "Sight beyond Sight", "Featherfoot Grace", "Imminent Threat", "Break Enchantments"},
                                                                   {"Banner of Defense", "Banner of Discipline", "Banner of Strength", "Banner of Tactics", "Bull's Charge", "Kick", "Stomp", "Throw Bolas", "Fear Me!", "For Great Justice!", "On My Mark!", "Shake it Off!", "Dolyak Signet", "Signet of Fury", "Signet of Might", "Signet of Stamina", "Balanced Stance", "Berserker Stance", "Endure Pain", "Frenzy", "Flow Stabilizer", "Bulletproof Barrier", "Electric Fence", "Dragonspike Mine"}};
static const std::vector<std::vector<string>> war_eliteskills = {{"Battle Standard", "Rampage", "Signet of Rage"},
                                                                 {"Battle Standard", "Rampage", "Signet of Rage", "Head Butt"},
                                                                 {"Battle Standard", "Rampage", "Signet of Rage", "Winds of Disenchantment"},
                                                                 {"Battle Standard", "Rampage", "Signet of Rage", "Tactical Reload"}};


static const std::vector<std::vector<string>> war_weapons = {{"Greatsword", "Hammer", "Longbow", "Rifle", "Axe", "Mace", "Sword"},
                                                             {"Greatsword", "Hammer", "Longbow", "Rifle", "Axe", "Mace", "Sword"},
                                                             {"Greatsword", "Hammer", "Longbow", "Rifle", "Axe", "Mace", "Sword", "Dagger"},
                                                             {"Greatsword", "Hammer", "Longbow", "Rifle", "Axe", "Mace", "Sword"}};
static const std::vector<std::vector<string>> war_offweapons = {{"Axe", "Mace", "Shield", "Sword", "Warhorn"},
                                                                {"Axe", "Mace", "Shield", "Sword", "Warhorn", "Torch"},
                                                                {"Axe", "Mace", "Shield", "Sword", "Warhorn", "Dagger"},
                                                                {"Axe", "Mace", "Shield", "Sword", "Warhorn", "Pistol"}};


static const std::vector<std::string> engi_specializations = {"Explosives", "Firearms", "Inventions", "Alchemy", "Tools",
                                                              "Scrapper", "Holosmith", "Mechanist"};


static const std::vector<std::vector<string>> explosives_traits = {{"Grenadier", "Short Fuse", "Glass Cannon"},
                                                                   {"Aim-Assisted Rocket", "Explosive Temper", "Blast Shield"},
                                                                   {"Flashbang", "Shrapnel", "Big Boomer"}};
static const std::vector<std::vector<string>> firearms_traits = {{"Chemical Rounds", "Sanguine Array", "High Caliber"},
                                                                 {"Pinpoint Distribution", "Thermal Vision", "No Scope"},
                                                                 {"Juggernaut", "Modified Ammunition", "Incendiary Powder"}};
static const std::vector<std::vector<string>> inventions_traits = {{"Over Shield", "Automated Medical Response", "Autodefense Bomb Dispenser"},
                                                                   {"Experimental Turrets", "Soothing Detonation", "Mecha Legs"},
                                                                   {"Anticorrosion Plating", "Bunker Down", "Medical Dispersion Field"}};
static const std::vector<std::vector<string>> alchemy_traits = {{"Invigorating Speed", "Protection Injection", "Health Insurance"},
                                                                {"Comeback Cure", "Emergency Elixir", "Backpack Regenerator"},
                                                                {"HGH", "Purity of Purpose", "Iron Blooded"}};
static const std::vector<std::vector<string>> tools_traits = {{"Static Discharge", "Reactive Lenses", "Power Wrench"},
                                                              {"Streamlined Kits", "Lock On", "Takedown Round"},
                                                              {"Kinetic Battery", "Adrenal Implant", "Gadgeteer"}};
static const std::vector<std::vector<string>> scrapper_traits = {{"Gyroscopic Acceleration", "System Shocker", "Mass Momentum"},
                                                                 {"Damage Dampener", "Expert Examination", "Object in Motion"},
                                                                 {"Adaptive Armor", "Kinetic Accelerators", "Applied Force"}};
static const std::vector<std::vector<string>> holosmith_traits = {{"Light Density Amplifier", "Prismatic Converter", "Solar Focusing Lens"},
                                                                  {"Crystal Configuration: Storm", "Crystal Configuration: Eclipse", "Crystal Configuration: Zephyr"},
                                                                  {"Thermal Release Valve", "Enhanced Capacity Storage Unit", "Photonic Blasting Module"}};
static const std::vector<std::vector<string>> mechanist_traits = {{"Mech Arms: Single-Edge Cutters", "Mech Arms: High-Impact Drivers", "Mech Arms: Jade Cannons"},
                                                                  {"Mech Frame: Conductive Alloys", "Mech Frame: Channeling Conduits", "Mech Frame: Variable Mass Distributor"},
                                                                  {"Mech Core: Jade Dynamo", "Mech Core: Barrier Engine", "Mech Core: J-Drive"}};


static const std::vector<std::vector<string>> engi_healskills = {{"A.E.D.", "Elixir H", "Healing Turret", "Med Kit"},
                                                         {"A.E.D.", "Elixir H", "Healing Turret", "Med Kit", "Medic Gyro"},
                                                         {"A.E.D.", "Elixir H", "Healing Turret", "Med Kit", "Coolant Blast"},
                                                         {"A.E.D.", "Elixir H", "Healing Turret", "Med Kit", "Rectifier Signet"}};
static const std::vector<std::vector<string>> engi_utilityskills = {{"Bomb Kit", "Grenade Kit", "Elixir Gun", "Flamethrower", "Tool Kit", "Elixir B", "Elixir C", "Elixir R", "Elixir S", "Elixir U", "Personal Battering Ram", "Rocket Boots", "Slick Shoes", "Throw Mine", "Utility Goggles", "Flame Turret", "Net Turret", "Rifle Turret", "Rocket Turret", "Thumper Turret"},
                                                            {"Bomb Kit", "Grenade Kit", "Elixir Gun", "Flamethrower", "Tool Kit", "Elixir B", "Elixir C", "Elixir R", "Elixir S", "Elixir U", "Personal Battering Ram", "Rocket Boots", "Slick Shoes", "Throw Mine", "Utility Goggles", "Flame Turret", "Net Turret", "Rifle Turret", "Rocket Turret", "Thumper Turret", "Blast Gyro", "Bulwark Gyro", "Purge Gyro", "Shredder Gyro"},
                                                            {"Bomb Kit", "Grenade Kit", "Elixir Gun", "Flamethrower", "Tool Kit", "Elixir B", "Elixir C", "Elixir R", "Elixir S", "Elixir U", "Personal Battering Ram", "Rocket Boots", "Slick Shoes", "Throw Mine", "Utility Goggles", "Flame Turret", "Net Turret", "Rifle Turret", "Rocket Turret", "Thumper Turret", "Spectrum Shield", "Hard Light Arena", "Laser Disk", "Photon Wall"},
                                                            {"Bomb Kit", "Grenade Kit", "Elixir Gun", "Flamethrower", "Tool Kit", "Elixir B", "Elixir C", "Elixir R", "Elixir S", "Elixir U", "Personal Battering Ram", "Rocket Boots", "Slick Shoes", "Throw Mine", "Utility Goggles", "Flame Turret", "Net Turret", "Rifle Turret", "Rocket Turret", "Thumper Turret", "Barrier Signet", "Force Signet", "Shift Signet", "Superconducting Signet"}};
static const std::vector<std::vector<string>> engi_eliteskills = {{"Elite Mortar Kit", "Elixir X", "Supply Crate"},
                                                          {"Elite Mortar Kit", "Elixir X", "Supply Crate", "Sneak Gyro"},
                                                          {"Elite Mortar Kit", "Elixir X", "Supply Crate", "Prime Light Beam"},
                                                          {"Elite Mortar Kit", "Elixir X", "Supply Crate", "Overclock Signet"}};


static const std::vector<std::vector<string>> engi_weapons = {{"Rifle", "Pistol"},
                                                              {"Rifle", "Pistol", "Hammer"},
                                                              {"Rifle", "Pistol", "Sword"},
                                                              {"Rifle", "Pistol", "Mace"}};
static const std::vector<std::vector<string>> engi_offweapons = {{"Pistol", "Shield"},
                                                                 {"Pistol", "Shield"},
                                                                 {"Pistol", "Shield"},
                                                                 {"Pistol", "Shield"}};


static const std::vector<std::string> rang_specializations = {"Marksmanship", "Skirmishing", "Wilderness Survival", "Nature Magic", "Beastmastery",
                                                              "Druid", "Soulbeast", "Untamed"};


static const std::vector<std::vector<string>> marksmanship_traits = {{"Stoneform", "Hunter's Gaze", "Clarion Bond"},
                                                                     {"Brutish Seals", "Farsighted", "Moment of Clarity"},
                                                                     {"Predator's Onslaught", "Remorseless", "Lead the Wind"}};
static const std::vector<std::vector<string>> skirmishing_traits = {{"Sharpened Edges", "Primal Reflexes", "Trapper's Expertise"},
                                                                    {"Spotter", "Strider's Defense", "Hidden Barbs"},
                                                                    {"Quick Draw", "Light on your Feet", "Vicious Quarry"}};
static const std::vector<std::vector<string>> wildernesssurvival_traits = {{"Child of Earth", "Oakheart Salve", "Taste for Danger"},
                                                                           {"Ambidexterity", "Refined Toxins", "Shared Anguish"},
                                                                           {"Empathic Bond", "Wilderness Knowledge", "Poison Master"}};
static const std::vector<std::vector<string>> naturemagic_traits = {{"Bountiful Hunter", "Instinctive Reaction", "Allies' Aid"},
                                                                    {"Evasive Purity", "Spirited Arrival", "Windborne Notes"},
                                                                    {"Nature's Vengeance", "Protective Ward", "Invigorating Bond"}};
static const std::vector<std::vector<string>> beastmastery_traits = {{"Go for the Eyes", "Potent Ally", "Resounding Timbre"},
                                                                     {"Wilting Strike", "Two-Handed Training", "Natural Healing"},
                                                                     {"Beastly Warden", "Zephyr's Speed", "Honed Axes"}};
static const std::vector<std::vector<string>> druid_traits = {{"Druidic Clarity", "Cultivated Synergy", "Primal Echoes"},
                                                              {"Celestial Shadow", "Verdant Etching", "Natural Stride"},
                                                              {"Grace of the Land", "Lingering Light", "Ancient Seeds"}};
static const std::vector<std::vector<string>> soulbeast_traits = {{"Fresh Reinforcement", "Live Fast", "Unstoppable Union"},
                                                                  {"Second Skin", "Essence of Speed", "Predator's Cunning"},
                                                                  {"Eternal Bond", "Leader of the Pack", "Oppressive Superiority"}};
static const std::vector<std::vector<string>> untamed_traits = {{"Debilitating Blows", "Nature's Shield", "Blinding Outburst"},
                                                                {"Enahncing Impact", "Cleansing Unleash", "Corrupting Vines"},
                                                                {"Fervent Force", "Restorative Strikes", "Ferocious Symbiosis"}};


static const std::vector<std::vector<string>> rang_healskills = {{"We Heal As One!", "Water Spirit", "Troll Unguent", "Healing Spring"},
                                                                 {"We Heal As One!", "Water Spirit", "Troll Unguent", "Healing Spring", "Glyph of Rejuvenation"},
                                                                 {"We Heal As One!", "Water Spirit", "Troll Unguent", "Healing Spring", "Bear Stance"},
                                                                 {"We Heal As One!", "Water Spirit", "Troll Unguent", "Healing Spring", "Perilous Gift"}};
static const std::vector<std::vector<string>> rang_utilityskills = {{"Guard!", "Protect Me!", "Search and Rescue!", "Sic 'Em!", "Signet of Renewal", "Signet of Stone", "Signet of the Hunt", "Signet of the Wild", "Frost Spirit", "Stone Spirit", "Storm Spirit", "Sun Spirit", "Lightning Reflexes", "Muddy Terrain", "Quickening Zephyr", "Sharpening Stone", "Flame Trap", "Frost Trap", "Spike Trap", "Viper's Nest"},
                                                                    {"Guard!", "Protect Me!", "Search and Rescue!", "Sic 'Em!", "Signet of Renewal", "Signet of Stone", "Signet of the Hunt", "Signet of the Wild", "Frost Spirit", "Stone Spirit", "Storm Spirit", "Sun Spirit", "Lightning Reflexes", "Muddy Terrain", "Quickening Zephyr", "Sharpening Stone", "Flame Trap", "Frost Trap", "Spike Trap", "Viper's Nest", "Glyph of Alignment", "Glyph of Equality", "Glyph of Unity", "Glyph of Tides"},
                                                                    {"Guard!", "Protect Me!", "Search and Rescue!", "Sic 'Em!", "Signet of Renewal", "Signet of Stone", "Signet of the Hunt", "Signet of the Wild", "Frost Spirit", "Stone Spirit", "Storm Spirit", "Sun Spirit", "Lightning Reflexes", "Muddy Terrain", "Quickening Zephyr", "Sharpening Stone", "Flame Trap", "Frost Trap", "Spike Trap", "Viper's Nest", "Dolyak Stance", "Griffon Stance", "Moa Stance", "Vulture Stance"},
                                                                    {"Guard!", "Protect Me!", "Search and Rescue!", "Sic 'Em!", "Signet of Renewal", "Signet of Stone", "Signet of the Hunt", "Signet of the Wild", "Frost Spirit", "Stone Spirit", "Storm Spirit", "Sun Spirit", "Lightning Reflexes", "Muddy Terrain", "Quickening Zephyr", "Sharpening Stone", "Flame Trap", "Frost Trap", "Spike Trap", "Viper's Nest", "Exploding Spores", "Mutate Conditions", "Unnatural Traversal", "Nature's Binding"}};
static const std::vector<std::vector<string>> rang_eliteskills = {{"Strength of the Pack!", "Spirit of Nature", "Entangle"},
                                                                  {"Strength of the Pack!", "Spirit of Nature", "Entangle", "Glyph of the Stars"},
                                                                  {"Strength of the Pack!", "Spirit of Nature", "Entangle", "One Wolf Pack"},
                                                                  {"Strength of the Pack!", "Spirit of Nature", "Entangle", "Forest's Fortification"}};


static const std::vector<std::vector<string>> rang_weapons = {{"Greatsword", "Longbow", "Shortbow", "Axe", "Sword"},
                                                              {"Greatsword", "Longbow", "Shortbow", "Axe", "Sword", "Staff"},
                                                              {"Greatsword", "Longbow", "Shortbow", "Axe", "Sword", "Dagger"},
                                                              {"Greatsword", "Longbow", "Shortbow", "Axe", "Sword", "Hammer"}};
static const std::vector<std::vector<string>> rang_offweapons = {{"Axe", "Dagger", "Torch", "Warhorn"},
                                                                 {"Axe", "Dagger", "Torch", "Warhorn"},
                                                                 {"Axe", "Dagger", "Torch", "Warhorn"},
                                                                 {"Axe", "Dagger", "Torch", "Warhorn"}};


static const std::vector<std::string> thief_specializations = {"Deadly Arts", "Critical Strikes", "Shadow Arts", "Acrobatics", "Trickery",
                                                               "Daredevil", "Deadeye", "Specter"};


static const std::vector<std::vector<string>> deadlyarts_traits = {{"Dagger Training", "Mug", "Deadly Ambition"},
                                                                   {"Even the Odds", "Panic Strike", "Revealed Training"},
                                                                   {"Potent Poison", "Improvisation", "Executioner"}};
static const std::vector<std::vector<string>> criticalstrikes_traits = {{"Assassin's Fury", "Signets of Power", "Twin Fangs"},
                                                                        {"Sundering Shade", "Practiced Tolerance", "Deadly Aim"},
                                                                        {"No Quarter", "Hidden Killer", "Invigorating Precision"}};
static const std::vector<std::vector<string>> shadowarts_traits = {{"Merciful Ambush", "Shadow's Embrace", "Hidden Thief"},
                                                                   {"Shadow Savior", "Leeching Venoms", "Flickering Shadows"},
                                                                   {"Cloaked in Shadow", "Shadow's Rejuvenation", "Rending Shade"}};
static const std::vector<std::vector<string>> acrobatics_traits = {{"Instant Reflexes", "Vigorous Recovery", "Pain Response"},
                                                                   {"Guarded Initiation", "Swindler's Equilibrium", "Hard to Catch"},
                                                                   {"Assassin's Reward", "Upper Hand", "Don't Stop"}};
static const std::vector<std::vector<string>> trickery_traits = {{"Uncatchable", "Burst of Agility", "Thrill of the Crime"},
                                                                 {"Bountiful Theft", "Trickster", "Pressure Striking"},
                                                                 {"Quick Pockets", "Sleight of Hand", "Deadly Ambush"}};
static const std::vector<std::vector<string>> daredevil_traits = {{"Marauder's Resilience", "Escapist's Fortitude", "Brawler's Tenacity"},
                                                                  {"Staff Master", "Havoc Specialist", "Impacting Disruption"},
                                                                  {"Lotus Training", "Unhindered Combatant", "Bounding Dodger"}};
static const std::vector<std::vector<string>> deadeye_traits = {{"Malicious Intent", "Collateral Damage", "One in the Chamber"},
                                                                {"Silent Scope", "Payback", "Premeditation"},
                                                                {"Maleficient Seven", "Be Quick or Be Killed", "Fire for Effect"}};
static const std::vector<std::vector<string>> specter_traits = {{"Second Opinion", "Shallow Grave", "Consume Shadows"},
                                                                {"Larcenous Torment", "Amplified Siphoning", "Traversing Darkness"},
                                                                {"Strength of Shadows", "Hungering Darkness", "Shadestep"}};


static const std::vector<std::vector<string>> thief_healskills = {{"Hide in Shadows", "Signet of Malice", "Withdraw", "Skelk Venom"},
                                                                  {"Hide in Shadows", "Signet of Malice", "Withdraw", "Skelk Venom", "Channeled Vigor"},
                                                                  {"Hide in Shadows", "Signet of Malice", "Withdraw", "Skelk Venom", "Malicious Restoration"},
                                                                  {"Hide in Shadows", "Signet of Malice", "Withdraw", "Skelk Venom", "Well of Gloom"}};
static const std::vector<std::vector<string>> thief_utilityskills = {{"Blinding Powder", "Shadow Refuge", "Shadowstep", "Smoke Screen", "Prepare Pitfall", "Prepare Thousand Needles", "Prepare Shadow Portal", "Prepare Seal Area", "Assassin's Signet", "Infiltrator's Signet", "Signet of Agility", "Signet of Shadows", "Caltrops", "Haste", "Roll for Initiative", "Scorpion Wire", "Devourer Venom", "Ice Drake Venom", "Skale Venom", "Spider Venom"},
                                                                     {"Blinding Powder", "Shadow Refuge", "Shadowstep", "Smoke Screen", "Prepare Pitfall", "Prepare Thousand Needles", "Prepare Shadow Portal", "Prepare Seal Area", "Assassin's Signet", "Infiltrator's Signet", "Signet of Agility", "Signet of Shadows", "Caltrops", "Haste", "Roll for Initiative", "Scorpion Wire", "Devourer Venom", "Ice Drake Venom", "Skale Venom", "Spider Venom", "Bandit's Defense", "Distracting Daggers", "Fist Flurry", "Impairing Daggers"},
                                                                     {"Blinding Powder", "Shadow Refuge", "Shadowstep", "Smoke Screen", "Prepare Pitfall", "Prepare Thousand Needles", "Prepare Shadow Portal", "Prepare Seal Area", "Assassin's Signet", "Infiltrator's Signet", "Signet of Agility", "Signet of Shadows", "Caltrops", "Haste", "Roll for Initiative", "Scorpion Wire", "Devourer Venom", "Ice Drake Venom", "Skale Venom", "Spider Venom", "Binding Shadow", "Mercy", "Shadow Flare", "Shadow Gust"},
                                                                     {"Blinding Powder", "Shadow Refuge", "Shadowstep", "Smoke Screen", "Prepare Pitfall", "Prepare Thousand Needles", "Prepare Shadow Portal", "Prepare Seal Area", "Assassin's Signet", "Infiltrator's Signet", "Signet of Agility", "Signet of Shadows", "Caltrops", "Haste", "Roll for Initiative", "Scorpion Wire", "Devourer Venom", "Ice Drake Venom", "Skale Venom", "Spider Venom", "Well of Bounty", "Well of Tears", "Well of Silence", "Well of Sorrow"}};
static const std::vector<std::vector<string>> thief_eliteskills = {{"Thieves Guild", "Basilisk Venom", "Dagger Storm"},
                                                                   {"Thieves Guild", "Basilisk Venom", "Dagger Storm", "Impact Strike"},
                                                                   {"Thieves Guild", "Basilisk Venom", "Dagger Storm", "Shadow Meld"},
                                                                   {"Thieves Guild", "Basilisk Venom", "Dagger Storm", "Shadowfall"}};


static const std::vector<std::vector<string>> thief_weapons = {{"Shortbow", "Dagger", "Pistol", "Sword"},
                                                               {"Shortbow", "Dagger", "Pistol", "Sword", "Staff"},
                                                               {"Shortbow", "Dagger", "Pistol", "Sword", "Deadeye"},
                                                               {"Shortbow", "Dagger", "Pistol", "Sword", "Scepter"}};
static const std::vector<std::vector<string>> thief_offweapons = {{"Dagger", "Pistol"},
                                                                  {"Dagger", "Pistol"},
                                                                  {"Dagger", "Pistol"},
                                                                  {"Dagger", "Pistol"}};


static const std::vector<std::string> ele_specializations = {"Fire", "Air", "Earth", "Water", "Arcane",
                                                             "Tempest", "Weaver", "Catalyst"};


static const std::vector<std::vector<string>> fire_traits = {{"Burning Precision", "Conjurer", "Burning Fire"},
                                                             {"Burning Rage", "Smothering Auras", "Power Overwhelming"},
                                                             {"Persisting Flames", "Pyromancer's Puissance", "Blinding Ashes"}};
static const std::vector<std::vector<string>> air_traits = {{"Zephyr's Boon", "One with Air", "Ferocious Winds"},
                                                            {"Inscription", "Raging Storm", "Stormsoul"},
                                                            {"Bolt to the Heart", "Fresh Air", "Lightning Rod"}};
static const std::vector<std::vector<string>> earth_traits = {{"Earth's Embrace", "Serrated Stones", "Elemental Shielding"},
                                                              {"Strength of Stone", "Rock Solid", "Earthen Blessing"},
                                                              {"Diamond Skin", "Written in Stone", "Stone Heart"}};
static const std::vector<std::vector<string>> water_traits = {{"Soothing Ice", "Piercing Shards", "Stop, Drop, and Roll"},
                                                              {"Soothing Disruption", "Cleansing Wave", "Flow like Water"},
                                                              {"Cleansing Water", "Powerful Aura", "Soothing Power"}};
static const std::vector<std::vector<string>> arcane_traits = {{"Arcane Precision", "Renewing Stamina", "Arcane Restoration"},
                                                               {"Arcane Resurrection", "Elemental Lockdown", "Final Shielding"},
                                                               {"Evasive Arcana", "Elemental Surge", "Bountiful Power"}};
static const std::vector<std::vector<string>> tempest_traits = {{"Gale Song", "Latent Stamina", "Unstable Conduit"},
                                                                {"Tempestuous Aria", "Harmonious Conduit", "Invigorating Torrents"},
                                                                {"Transcendent Tempest", "Lucid Singularity", "Elemental Bastion"}};
static const std::vector<std::vector<string>> weaver_traits = {{"Superior Elements", "Elemental Pursuit", "Master's Fortitude"},
                                                               {"Weaver's Prowess", "Swift Revenge", "Bolstered Elements"},
                                                               {"Elements of Rage", "Woven Stride", "Invigorating Strikes"}};
static const std::vector<std::vector<string>> catalyst_traits = {{"Hardened Auras", "Vicious Empowerment", "Energized Elements"},
                                                                 {"Empowering Auras", "Evasive Empowerment", "Spectacular Sphere"},
                                                                 {"Staunch Auras", "Empowered Empowerment", "Sphere Specialist"}};


static const std::vector<std::vector<string>> ele_healskills = {{"Arcane Brilliance", "Ether Renewal", "Glyph of Elemental Harmony", "Signet of Restoration"},
                                                                {"Arcane Brilliance", "Ether Renewal", "Glyph of Elemental Harmony", "Signet of Restoration", "Wash the Pain Away!"},
                                                                {"Arcane Brilliance", "Ether Renewal", "Glyph of Elemental Harmony", "Signet of Restoration", "Aquatic Stance"},
                                                                {"Arcane Brilliance", "Ether Renewal", "Glyph of Elemental Harmony", "Signet of Restoration", "Soothing Water"}};
static const std::vector<std::vector<string>> ele_utilityskills = {{"Arcane Blast", "Arcane Power", "Arcane Shield", "Arcane Wave", "Armor of Earth", "Cleansing Fire", "Lightning Flash", "Mist Form", "Conjure Earth Shield", "Conjure Flame Axe", "Conjure Frost Bow", "Conjure Lightning Hammer", "Glyph of Elemental Power", "Glyph of Lesser Elementals", "Glyph of Renewal", "Glyph of Storms", "Signet of Air", "Signet of Earth", "Signet of Fire", "Signet of Water"},
                                                                   {"Arcane Blast", "Arcane Power", "Arcane Shield", "Arcane Wave", "Armor of Earth", "Cleansing Fire", "Lightning Flash", "Mist Form", "Conjure Earth Shield", "Conjure Flame Axe", "Conjure Frost Bow", "Conjure Lightning Hammer", "Glyph of Elemental Power", "Glyph of Lesser Elementals", "Glyph of Renewal", "Glyph of Storms", "Signet of Air", "Signet of Earth", "Signet of Fire", "Signet of Water", "Feel the Burn!", "Eye of the Storm!", "Aftershock!", "Flash-Freeze"},
                                                                   {"Arcane Blast", "Arcane Power", "Arcane Shield", "Arcane Wave", "Armor of Earth", "Cleansing Fire", "Lightning Flash", "Mist Form", "Conjure Earth Shield", "Conjure Flame Axe", "Conjure Frost Bow", "Conjure Lightning Hammer", "Glyph of Elemental Power", "Glyph of Lesser Elementals", "Glyph of Renewal", "Glyph of Storms", "Signet of Air", "Signet of Earth", "Signet of Fire", "Signet of Water", "Primordial Stance", "Stone Resonance", "Unravel", "Twist of Fate"},
                                                                   {"Arcane Blast", "Arcane Power", "Arcane Shield", "Arcane Wave", "Armor of Earth", "Cleansing Fire", "Lightning Flash", "Mist Form", "Conjure Earth Shield", "Conjure Flame Axe", "Conjure Frost Bow", "Conjure Lightning Hammer", "Glyph of Elemental Power", "Glyph of Lesser Elementals", "Glyph of Renewal", "Glyph of Storms", "Signet of Air", "Signet of Earth", "Signet of Fire", "Signet of Water", "Relentless Fire", "Shattering Ice", "Invigorating Air", "Fortified Earth"}};
static const std::vector<std::vector<string>> ele_eliteskills = {{"Conjure Fiery Greatsword", "Glyph of Elementals", "Tornado"},
                                                                 {"Conjure Fiery Greatsword", "Glyph of Elementals", "Tornado", "Rebound!"},
                                                                 {"Conjure Fiery Greatsword", "Glyph of Elementals", "Tornado", "Weave Self"},
                                                                 {"Conjure Fiery Greatsword", "Glyph of Elementals", "Tornado", "Elemental Celerity"}};


static const std::vector<std::vector<string>> ele_weapons = {{"Staff", "Dagger", "Scepter"},
                                                             {"Staff", "Dagger", "Scepter"},
                                                             {"Staff", "Dagger", "Scepter", "Sword"},
                                                             {"Staff", "Dagger", "Scepter", "Hammer"}};
static const std::vector<std::vector<string>> ele_offweapons = {{"Dagger", "Focus"},
                                                                {"Dagger", "Focus", "Warhorn"},
                                                                {"Dagger", "Focus"},
                                                                {"Dagger", "Focus"}};


static const std::vector<std::string> mes_specializations = {"Domination", "Dueling", "Chaos", "Inspiration", "Illusions",
                                                             "Chronomancer", "Mirage", "Virtuoso"};


static const std::vector<std::vector<string>> domination_traits = {{"Bountiful Blades", "Empowered Illusions", "Rending Shatter"},
                                                                   {"Shattered Concentration", "Egotism", "Furious Interruption"},
                                                                   {"Vicious Expression", "Mental Anguish", "Power Block"}};
static const std::vector<std::vector<string>> dueling_traits = {{"Phantasmal Fury", "Desperate Decoy", "Duelist's Discipline"},
                                                                {"Blinding Dissipation", "Evasive Mirror", "Fencer's Finesse"},
                                                                {"Superiority Complex", "Ineptitude", "Deceptive Evasion"}};
static const std::vector<std::vector<string>> chaos_traits = {{"Method of Madness", "Illusionary Defense", "Master of Manipulation"},
                                                              {"Auspicious Anguish", "Chaotic Transference", "Chaotic Potency"},
                                                              {"Chaotic Interruption", "Prismatic Understanding", "Bountiful Disillusionment"}};
static const std::vector<std::vector<string>> inspiration_traits = {{"Medic's Feedback", "Restorative Mantras", "Sympathetic Visage"},
                                                                    {"Warden's Feedback", "Restorative Illusions", "Protected Phantasms"},
                                                                    {"Mental Defense", "Illusionary Inspiration", "Blurred Inscriptions"}};
static const std::vector<std::vector<string>> illusions_traits = {{"Shatter Storm", "Persistence of Memory", "The Pledge"},
                                                                  {"Escape Artist", "Phantasmal Haste", "Maim the Disillusioned"},
                                                                  {"Phantasmal Force", "Master of Fragmentation", "Malicious Sorcery"}};
static const std::vector<std::vector<string>> chronomancer_traits = {{"Delayed Reactions", "Time Catches Up", "All's Well That Ends Well"},
                                                                     {"Danger Time", "Illusionary Reversion", "Improved Alacrity"},
                                                                     {"Lost Time", "Seize the Moment", "Chronophantasma"}};
static const std::vector<std::vector<string>> mirage_traits = {{"Self-Deception", "Renewing Oasis", "Riddle of Sand"},
                                                               {"Desert Distortion", "Mirage Mantle", "Mirrored Axes"},
                                                               {"Infinite Horizon", "Elusive Mind", "Dune Cloak"}};
static const std::vector<std::vector<string>> virtuoso_traits = {{"Bladeturn Refrain", "Mental Focus", "Jagged Mind"},
                                                                 {"Duelist's Reversal", "Phantasmal Blades", "Sharpening Sorrow"},
                                                                 {"Psychic Riposte", "Infinite Forge", "Bloodsong"}};


static const std::vector<std::vector<string>> mes_healskills = {{"Ether Feast", "Mirror", "Mantra of Recovery", "Signet of the Ether"},
                                                                {"Ether Feast", "Mirror", "Mantra of Recovery", "Signet of the Ether", "Well of Eternity"},
                                                                {"Ether Feast", "Mirror", "Mantra of Recovery", "Signet of the Ether", "False Oasis"},
                                                                {"Ether Feast", "Mirror", "Mantra of Recovery", "Signet of the Ether", "Twin Blade Restoration"}};
static const std::vector<std::vector<string>> mes_utilityskills = {{"Decoy", "Mirror Images", "Feedback", "Null Field", "Portal Entre", "Veil", "Arcane Thievery", "Blink", "Illusion of Life", "Mimic", "Mantra of Concentration", "Mantra of Distraction", "Mantra of Pain", "Mantra of Resolve", "Phantasmal Defender", "Phantasmal Disenchanter", "Signet of Domination", "Signet of Illusions", "Signet of Inspiration", "Signet of Midnight"},
                                                                   {"Decoy", "Mirror Images", "Feedback", "Null Field", "Portal Entre", "Veil", "Arcane Thievery", "Blink", "Illusion of Life", "Mimic", "Mantra of Concentration", "Mantra of Distraction", "Mantra of Pain", "Mantra of Resolve", "Phantasmal Defender", "Phantasmal Disenchanter", "Signet of Domination", "Signet of Illusions", "Signet of Inspiration", "Signet of Midnight", "Well of Action", "Well of Calamity", "Well of Precognition", "Well of Recall"},
                                                                   {"Decoy", "Mirror Images", "Feedback", "Null Field", "Portal Entre", "Veil", "Arcane Thievery", "Blink", "Illusion of Life", "Mimic", "Mantra of Concentration", "Mantra of Distraction", "Mantra of Pain", "Mantra of Resolve", "Phantasmal Defender", "Phantasmal Disenchanter", "Signet of Domination", "Signet of Illusions", "Signet of Inspiration", "Signet of Midnight", "Crystal Sands", "Illusionary Ambush", "Mirage Advance", "Sand through Glass"},
                                                                   {"Decoy", "Mirror Images", "Feedback", "Null Field", "Portal Entre", "Veil", "Arcane Thievery", "Blink", "Illusion of Life", "Mimic", "Mantra of Concentration", "Mantra of Distraction", "Mantra of Pain", "Mantra of Resolve", "Phantasmal Defender", "Phantasmal Disenchanter", "Signet of Domination", "Signet of Illusions", "Signet of Inspiration", "Signet of Midnight", "Blade Renewal", "Rain of Swords", "Psychic Force", "Sword of Decimation"}};
static const std::vector<std::vector<string>> mes_eliteskills = {{"Time Warp", "Mass Invisibility", "Signet of Humility"},
                                                                 {"Time Warp", "Mass Invisibility", "Signet of Humility", "Gravity Well"},
                                                                 {"Time Warp", "Mass Invisibility", "Signet of Humility", "Jaunt"},
                                                                 {"Time Warp", "Mass Invisibility", "Signet of Humility", "Thousand Cuts"}};


static const std::vector<std::vector<string>> mes_weapons = {{"Greatsword", "Staff", "Scepter", "Sword"},
                                                             {"Greatsword", "Staff", "Scepter", "Sword"},
                                                             {"Greatsword", "Staff", "Scepter", "Sword", "Axe"},
                                                             {"Greatsword", "Staff", "Scepter", "Sword", "Dagger"}};
static const std::vector<std::vector<string>> mes_offweapons = {{"Focus", "Pistol", "Sword", "Torch"},
                                                                {"Focus", "Pistol", "Sword", "Torch", "Shield"},
                                                                {"Focus", "Pistol", "Sword", "Torch"},
                                                                {"Focus", "Pistol", "Sword", "Torch"}};


static const std::vector<std::string> necro_specializations = {"Spite", "Curses", "Death Magic", "Blood Magic", "Soul Reaping",
                                                               "Reaper", "Scourge", "Harbinger"};


static const std::vector<std::vector<string>> spite_traits = {{"Spiteful Talisman", "Spiteful Renewal", "Bitter Chill"},
                                                              {"Chill of Death", "Awaken the Pain", "Signets of Suffering"},
                                                              {"Dread", "Close to Death", "Spiteful Spirit"}};
static const std::vector<std::vector<string>> curses_traits = {{"Insidious Disruption", "Plague Sending", "Chilling Darkness"},
                                                               {"Master of Corruption", "Path of Corruption", "Terror"},
                                                               {"Weakening Shroud", "Parasitic Contagion", "Lingering Curse"}};
static const std::vector<std::vector<string>> deathmagic_traits = {{"Flesh of the Master", "Putrid Defense", "Shrouded Removal"},
                                                                   {"Necromantic Corruption", "Dark Defiance", "Deadly Strength"},
                                                                   {"Death Nova", "Corrupter's Fervor", "Unholy Sanctuary"}};
static const std::vector<std::vector<string>> bloodmagic_traits = {{"Ritual of Life", "Quickening Thirst", "Blood Bond"},
                                                                   {"Life from Death", "Banshee's Wail", "Vampiric Presence"},
                                                                   {"Blood Bank", "Unholy Martyr", "Transfusion"}};
static const std::vector<std::vector<string>> soulreaping_traits = {{"Unyielding Blast", "Soul Marks", "Speed of Shadows"},
                                                                    {"Soul Barbs", "Vital Persistence", "Fear of Death"},
                                                                    {"Eternal Life", "Death Perception", "Dhuumfire"}};
static const std::vector<std::vector<string>> reaper_traits = {{"Augury of Death", "Chilling Nova", "Relentless Pursuit"},
                                                               {"Soul Eater", "Chilling Victory", "Decimate Defenses"},
                                                               {"Blighter's Boon", "Deathly Chill", "Reaper's Onslaught"}};
static const std::vector<std::vector<string>> scourge_traits = {{"Abrasive Grit", "Fell Beacon", "Nourishing Ashes"},
                                                                {"Desert Empowerment", "Sadistic Searing", "Herald of Sorrow"},
                                                                {"Sand Savant", "Demonic Lore", "Speed from Corruption"}};
static const std::vector<std::vector<string>> harbinger_traits = {{"Wicked Corruption", "Vile Vials", "Septic Corruption"},
                                                                  {"Implacable Foe", "Twisted Medicine", "Dark Gunslinger"},
                                                                  {"Cascading Corruption", "Deathly Haste", "Doom Approaches"}};


static const std::vector<std::vector<string>> necro_healskills = {{"Consume Conditions", "Summon Blood Fiend", "Signet of Vampirism", "Well of Blood"},
                                                                  {"Consume Conditions", "Summon Blood Fiend", "Signet of Vampirism", "Well of Blood", "Your Soul Is Mine!"},
                                                                  {"Consume Conditions", "Summon Blood Fiend", "Signet of Vampirism", "Well of Blood", "Sand Flare"},
                                                                  {"Consume Conditions", "Summon Blood Fiend", "Signet of Vampirism", "Well of Blood", "Elixir of Promise"}};
static const std::vector<std::vector<string>> necro_utilityskills = {{"Blood is Power", "Corrosive Poison Cloud", "Corrupt Boon", "Epidemic", "Summon Bone Fiend", "Summon Bone Minions", "Summon Flesh Wurm", "Summon Shadow Fiend", "Plague Signet", "Signet of Spite", "Signet of the Locust", "Signet of Undeath", "Spectral Armor", "Spectral Grasp", "Spectral Walk", "Spectral Ring", "Well of Corruption", "Well of Darkness", "Well of Power", "Well of Suffering"},
                                                                     {"Blood is Power", "Corrosive Poison Cloud", "Corrupt Boon", "Epidemic", "Summon Bone Fiend", "Summon Bone Minions", "Summon Flesh Wurm", "Summon Shadow Fiend", "Plague Signet", "Signet of Spite", "Signet of the Locust", "Signet of Undeath", "Spectral Armor", "Spectral Grasp", "Spectral Walk", "Spectral Ring", "Well of Corruption", "Well of Darkness", "Well of Power", "Well of Suffering", "Nothing Can Save You!", "Rise!", "Suffer!", "You Are All Weaklings!"},
                                                                     {"Blood is Power", "Corrosive Poison Cloud", "Corrupt Boon", "Epidemic", "Summon Bone Fiend", "Summon Bone Minions", "Summon Flesh Wurm", "Summon Shadow Fiend", "Plague Signet", "Signet of Spite", "Signet of the Locust", "Signet of Undeath", "Spectral Armor", "Spectral Grasp", "Spectral Walk", "Spectral Ring", "Well of Corruption", "Well of Darkness", "Well of Power", "Well of Suffering", "Trail of Anguish", "Desiccate", "Sand Swell", "Serpent Siphon"},
                                                                     {"Blood is Power", "Corrosive Poison Cloud", "Corrupt Boon", "Epidemic", "Summon Bone Fiend", "Summon Bone Minions", "Summon Flesh Wurm", "Summon Shadow Fiend", "Plague Signet", "Signet of Spite", "Signet of the Locust", "Signet of Undeath", "Spectral Armor", "Spectral Grasp", "Spectral Walk", "Spectral Ring", "Well of Corruption", "Well of Darkness", "Well of Power", "Well of Suffering", "Elixir of Risk", "Elixir of Anguish", "Elixir of Bliss", "Elixir of Ignorance"}};
static const std::vector<std::vector<string>> necro_eliteskills = {{"Plaguelands", "Summon Flesh Golem", "Lich Form"},
                                                                   {"Plaguelands", "Summon Flesh Golem", "Lich Form", "Chilled to the Bone!"},
                                                                   {"Plaguelands", "Summon Flesh Golem", "Lich Form", "Ghastly Breach"},
                                                                   {"Plaguelands", "Summon Flesh Golem", "Lich Form", "Elixir of Ambition"}};


static const std::vector<std::vector<string>> necro_weapons = {{"Staff", "Axe", "Dagger", "Scepter"},
                                                               {"Staff", "Axe", "Dagger", "Scepter", "Greatsword"},
                                                               {"Staff", "Axe", "Dagger", "Scepter"},
                                                               {"Staff", "Axe", "Dagger", "Scepter", "Pistol"}};
static const std::vector<std::vector<string>> necro_offweapons = {{"Dagger", "Focus", "Warhorn"},
                                                                  {"Dagger", "Focus", "Warhorn"},
                                                                  {"Dagger", "Focus", "Warhorn", "Torch"},
                                                                  {"Dagger", "Focus", "Warhorn"}};


static const std::vector<string> attribute_combos = {{"Berserker's", "Zealot's", "Soldier's", "Forsaken", "Valkyrie", "Harrier's", "Paladin",
                                                      "Commander's", "Demolisher", "Swashbuckler", "Marauder", "Avatar", "Destroyer", "Vigilant",
                                                      "Crusader", "Wanderer's", "Diviner's", "Dragon's", "Wizard", "Viper's", "Grieving", "Sage",
                                                      "Marshal's", "Captain's", "Rampager's", "Assassin's", "Seraph", "Knight's", "Cavalier's",
                                                      "Nomad's", "Settler's", "Giver's", "Trailblazer's", "Minstrel's", "Sentinel's", "Shaman's",
                                                      "Ritualist's", "Plaguedoctor's", "Sinister", "Carrion", "Rabid", "Dire", "Apostate's",
                                                      "Bringer's", "Cleric's", "Magi's", "Apothecary's", "Celestial"}};

static const std::vector<string> runes_list = {"Superior Rune of Altruism", "Superior Rune of Antitoxin", "Superior Rune of Balthazar", "Superior Rune of Divinity",
                                                "Superior Rune of Durability", "Superior Rune of Dwayna", "Superior Rune of Evasion", "Superior Rune of Exuberance",
                                                "Superior Rune of Fireworks", "Superior Rune of Grenth", "Superior Rune of Hoelbrak", "Superior Rune of Infiltration",
                                                "Superior Rune of Leadership", "Superior Rune of Lyssa", "Superior Rune of Melandru", "Superior RUne of Mercy",
                                                "Superior Rune of Nature's Bounty", "Superior Rune of Orr", "Superior Rune of Perplexity", "Superior Rune of Radiance",
                                                "Superior Rune of Rage", "Superior Rune of Rata Sum", "Superior Rune of Resistance", "Superior Rune of Sanctuary",
                                                "Superior Rune of Scavenging", "Superior Rune of Snowfall", "Superior Rune of Speed", "Superior Rune of Strength",
                                                "Superior Rune of Surging", "Superior Rune of Svanir", "Superior Rune of the Adventurer", "Superior Rune of the Afflicted",
                                                "Superior Rune of the Air", "Superior Rune of the Aristocracy", "Superior Rune of the Berserker", "Superior Rune of the Brawler",
                                                "Superior Rune of the Cavalier", "Superior Rune of the Centaur", "Superior Rune of the Chronomancer", "Superior Rune of the Citadel",
                                                "Superior Rune of the Daredevil", "Superior Rune of the Deadeye", "Superior Rune of the Defender", "Superior Rune of the Dolyak",
                                                "Superior Rune of the Dragonhunter", "Superior Rune of the Druid", "Superior Rune of the Eagle", "Superior Rune of the Earth",
                                                "Superior Rune of the Elementalist", "Superior Rune of the Engineer", "Superior Rune of the Fire", "Superior Rune of the Firebrand",
                                                "Superior Rune of the Flame Legion", "Superior Rune of the Flock", "Superior Rune of the Forgeman", "Superior Rune of the Golemancer",
                                                "Superior Rune of the Grove", "Superior Rune of the Guardian", "Superior Rune of the Herald", "Superior Rune of the Holosmith",
                                                "Superior Rune of the Ice", "Superior Rune of the Krait", "Superior Rune of the Lich", "Superior Rune of the Mad King",
                                                "Superior Rune of the Mesmer", "Superior Rune of the Mirage", "Superior Rune of the Monk", "Superior Rune of the Necromancer",
                                                "Superior Rune of the Nightmare", "Superior Rune of the Ogre", "Superior Rune of the Pack", "Superior Rune of the Privateer",
                                                "Superior Rune of the Ranger", "Superior Rune of the Reaper", "Superior Rune of the Rebirth", "Superior Rune of the Renegade",
                                                "Superior Rune of the Revenant", "Superior Rune of the Scholar", "Superior Rune of the Scourge", "Superior Rune of the Scrapper",
                                                "Superior Rune of the Soulbeast", "Superior Rune of the Spellbreaker", "Superior Rune of the Stars", "Superior Rune of the Sunless",
                                                "Superior Rune of the Tempest", "Superior Rune of the Thief", "Superior Rune of the Scrapper", "Superior Rune of the Traveler",
                                                "Superior Rune of the Trooper", "Superior Rune of the Undead", "Superior Rune of the Warrior", "Superior Rune of the Water",
                                                "Superior Rune of the Weaver", "Superior Rune of the Wurm", "Superior Rune of the Zephyrite", "Superior Rune of Thorns",
                                                "Superior Rune of Tormenting", "Superior Rune of Vampirism"};
static const std::vector<string> sigil_list = {"Superior Sigil of Absorption", "Superior Sigil of Accuracy", "Superior Sigil of Agility", "Superior Sigil of Agony",
                                               "Superior Sigil of Air", "Superior Sigil of Battle", "Superior Sigil of Benevolence", "Superior Sigil of Blight",
                                               "Superior Sigil of Blood", "Superior Sigil of Bloodlust", "Superior Sigil of Bounty", "Superior Sigil of Bursting",
                                               "Superior Sigil of Celerity", "Superior Sigil of Centaur Slaying", "Superior Sigil of Chilling", "Superior Sigil of Cleansing",
                                               "Superior Sigil of Concentration", "Superior Sigil of Corruption", "Superior Sigil of Cruelty", "Superior Sigil of Debility",
                                               "Superior Sigil of Demon Slaying", "Superior Sigil of Demons", "Superior Sigil of Destroyer Slaying", "Superior Sigil of Doom",
                                               "Superior Sigil of Draining", "Superior Sigil of Dreams", "Superior Sigil of Earth", "Superior Sigil of Elemental Slaying",
                                               "Superior Sigil of Energy", "Superior Sigil of Fire", "Superior Sigil of Force", "Superior Sigil of Frailty",
                                               "Superior Sigil of Frenzy", "Superior Sigil of Generosity", "Superior Sigil of Golemancy", "Superior Sigil of Ghost Slaying",
                                               "Superior Sigil of Grawl Slaying", "Superior Sigil of Hobbling", "Superior Sigil of Hologram Slaying", "Superior Sigil of Hydromancy",
                                               "Superior Sigil of Ice", "Superior Sigil of Icebrood Slaying", "Superior Sigl of Impact", "Superior Sigil of Incapacitation",
                                               "Superior Sigil of Justice", "Superior Sigil of Karka Slaying", "Supeiror Sigil of Leeching", "Superior Sigil of Life",
                                               "Superior Sigil of Luck", "Superior Sigil of Mad Scientists", "Superior Sigil of Malice", "Superior Sigil of Mischief",
                                               "Superior Sigil of Momentum", "Superior Sigil of Nullification", "Superor Sigil of Ogre Slaying", "Superior Sigil of Paralyzation",
                                               "Superior Sigil of Peril", "Superior Sigil of Purity", "Superior Sigil of Rage", "Superior Sigil of Rending",
                                               "Superior Sigil of Renewal", "Superior Sigil of Retoration", "Superior Sigil of Ruthlessness", "Superior Sigil of Serpent Slaying",
                                               "Superior Sigil of Severance", "Superior Sigil of Smoldering", "Superior Sigil of Sorrow", "Superior Sigil of Speed",
                                               "Superior Sigil of Stamina", "Superior Sigil of Strength", "Superior Sigil of the Night",  "Superior Sigil of Stars",
                                               "Superior Sigil of Torment", "Supeior Sigil of Transference", "Superior Sigil of Undead Slaying", "Superior Sigil of Venom",
                                               "Superior Sigil of Vision", "Superior Sigil of Water", "Superior Sigil of Wrath"};


int main() {
    srand((unsigned int)time(NULL));

    int x = rand() % 9;
    string profession = professions[x];
    cout << "Profession: " << profession << endl;
    cout << "================================================================" << endl;

    cout << "Traits: " << endl;
    vector<string> specializations;
    vector<vector<string>> traits;


    int active_elite = 0;
    int elite;


    while (specializations.size() != 3) {

        x = rand() % 8;
        string spec;

        if (x >= 5 && active_elite) {
            continue;
        }

        if (x >= 5) {
            active_elite = 1;
            elite = x - 4;
        }

        vector<string> temptraits;

        if (profession.compare("Guardian") == 0) {

            spec = guard_specializations[x];

            if (spec.compare("Zeal") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(zeal_traits[i][y]);
                }
            } else if (spec.compare("Radiance") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(radiance_traits[i][y]);
                }
            } else if (spec.compare("Valor") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(valor_traits[i][y]);
                }
            } else if (spec.compare("Honor") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(honor_traits[i][y]);
                }
            } else if (spec.compare("Virtues") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(virtues_traits[i][y]);
                }
            } else if (spec.compare("Dragonhunter") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(dragonhunter_traits[i][y]);
                }
            } else if (spec.compare("Firebrand") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(firebrand_traits[i][y]);
                }
            } else if (spec.compare("Willbender") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(willbender_traits[i][y]);
                }
            }

        } else if (profession.compare("Revenant") == 0) {
            spec = rev_specializations[x];

            if (spec.compare("Corruption") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(corruption_traits[i][y]);
                }
            } else if (spec.compare("Retribution") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(retribution_traits[i][y]);
                }
            } else if (spec.compare("Salvation") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(salvation_traits[i][y]);
                }
            } else if (spec.compare("Invocation") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(invocation_traits[i][y]);
                }
            } else if (spec.compare("Devastation") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(devastation_traits[i][y]);
                }
            } else if (spec.compare("Herald") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(herald_traits[i][y]);
                }
            } else if (spec.compare("Renegade") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(renegade_traits[i][y]);
                }
            } else if (spec.compare("Vindicator") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(vindicator_traits[i][y]);
                }
            }
        } else if (profession.compare("Warrior") == 0) {
            spec = war_specializations[x];

            if (spec.compare("Strength") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(strength_traits[i][y]);
                }
            } else if (spec.compare("Arms") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(arms_traits[i][y]);
                }
            } else if (spec.compare("Defense") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(defense_traits[i][y]);
                }
            } else if (spec.compare("Tactics") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(tactics_traits[i][y]);
                }
            } else if (spec.compare("Discipline") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(discipline_traits[i][y]);
                }
            } else if (spec.compare("Berserker") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(berserker_traits[i][y]);
                }
            } else if (spec.compare("Spellbreaker") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(spellbraker_traits[i][y]);
                }
            } else if (spec.compare("Bladesworn") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(bladesworn_traits[i][y]);
                }
            }
        } else if (profession.compare("Engineer") == 0) {
            spec = engi_specializations[x];

            if (spec.compare("Explosives") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(explosives_traits[i][y]);
                }
            } else if (spec.compare("Firearms") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(firearms_traits[i][y]);
                }
            } else if (spec.compare("Inventions") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(inventions_traits[i][y]);
                }
            } else if (spec.compare("Alchemy") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(alchemy_traits[i][y]);
                }
            } else if (spec.compare("Tools") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(tools_traits[i][y]);
                }
            } else if (spec.compare("Scrapper") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(scrapper_traits[i][y]);
                }
            } else if (spec.compare("Holosmith") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(holosmith_traits[i][y]);
                }
            } else if (spec.compare("Mechanist") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(mechanist_traits[i][y]);
                }
            }
        } else if (profession.compare("Ranger") == 0) {
            spec = rang_specializations[x];

            if (spec.compare("Marksmanship") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(marksmanship_traits[i][y]);
                }
            } else if (spec.compare("Skirmishing") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(skirmishing_traits[i][y]);
                }
            } else if (spec.compare("Wilderness Survival") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(wildernesssurvival_traits[i][y]);
                }
            } else if (spec.compare("Nature Magic") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(naturemagic_traits[i][y]);
                }
            } else if (spec.compare("Beastmastery") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(beastmastery_traits[i][y]);
                }
            } else if (spec.compare("Druid") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(druid_traits[i][y]);
                }
            } else if (spec.compare("Soulbeast") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(soulbeast_traits[i][y]);
                }
            } else if (spec.compare("Untamed") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(untamed_traits[i][y]);
                }
            }
        } else if (profession.compare("Thief") == 0) {
            spec = thief_specializations[x];

            if (spec.compare("Deadly Arts") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(deadlyarts_traits[i][y]);
                }
            } else if (spec.compare("Critical Strikes") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(criticalstrikes_traits[i][y]);
                }
            } else if (spec.compare("Shadow Arts") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(shadowarts_traits[i][y]);
                }
            } else if (spec.compare("Acrobatics") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(acrobatics_traits[i][y]);
                }
            } else if (spec.compare("Trickery") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(trickery_traits[i][y]);
                }
            } else if (spec.compare("Daredevil") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(daredevil_traits[i][y]);
                }
            } else if (spec.compare("Deadeye") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(deadeye_traits[i][y]);
                }
            } else if (spec.compare("Specter") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(specter_traits[i][y]);
                }
            }
        } else if (profession.compare("Elementalist") == 0) {
            spec = ele_specializations[x];

            if (spec.compare("Fire") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(fire_traits[i][y]);
                }
            } else if (spec.compare("Air") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(air_traits[i][y]);
                }
            } else if (spec.compare("Earth") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(earth_traits[i][y]);
                }
            } else if (spec.compare("Water") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(water_traits[i][y]);
                }
            } else if (spec.compare("Arcane") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(arcane_traits[i][y]);
                }
            } else if (spec.compare("Tempest") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(tempest_traits[i][y]);
                }
            } else if (spec.compare("Weaver") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(weaver_traits[i][y]);
                }
            } else if (spec.compare("Catalyst") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(catalyst_traits[i][y]);
                }
            }
        } else if (profession.compare("Mesmer") == 0) {
            spec = mes_specializations[x];

            if (spec.compare("Domination") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(domination_traits[i][y]);
                }
            } else if (spec.compare("Dueling") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(dueling_traits[i][y]);
                }
            } else if (spec.compare("Chaos") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(chaos_traits[i][y]);
                }
            } else if (spec.compare("Inspiration") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(inspiration_traits[i][y]);
                }
            } else if (spec.compare("Illusions") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(illusions_traits[i][y]);
                }
            } else if (spec.compare("Chronomancer") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(chronomancer_traits[i][y]);
                }
            } else if (spec.compare("Mirage") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(mirage_traits[i][y]);
                }
            } else if (spec.compare("Virtuoso") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(virtuoso_traits[i][y]);
                }
            }
        } else {
            spec = necro_specializations[x];

            if (spec.compare("Spite") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(spite_traits[i][y]);
                }
            } else if (spec.compare("Curses") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(curses_traits[i][y]);
                }
            } else if (spec.compare("Death Magic") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(deathmagic_traits[i][y]);
                }
            } else if (spec.compare("Blood Magic") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(bloodmagic_traits[i][y]);
                }
            } else if (spec.compare("Soul Reaping") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(soulreaping_traits[i][y]);
                }
            } else if (spec.compare("Reaper") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(reaper_traits[i][y]);
                }
            } else if (spec.compare("Scourge") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(scourge_traits[i][y]);
                }
            } else if (spec.compare("Harbinger") == 0) {
                for (int i = 0; i < 3; i++) {
                    int y = rand() % 3;
                    temptraits.push_back(harbinger_traits[i][y]);
                }
            }
        }

        if (find(specializations.begin(), specializations.end(), spec) == specializations.end()) {
            specializations.push_back(spec);
            traits.push_back(temptraits);

        }
    }

    for (int i = 0; i < specializations.size(); i++) {
        cout << specializations[i] << "- ";
        cout << traits[i][0] << ", " << traits[i][1] << ", " << traits[i][2] << endl;

        cout << "------" << endl;
    }

    vector<string> weapons;

    cout << "================================================================" << endl;
    if (profession.compare("Revenant") == 0) {
        vector<string> legends;
        cout << "Legends: ";

        while (legends.size() < 2) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            string legend = rev_legends[elite][x];
            if (find(legends.begin(), legends.end(), legend) == legends.end()) {
                legends.push_back(legend);
            }
        }

        cout << legends[0] << ", " << legends[1] << endl;

        while (weapons.size() < 2) {
            x = rand() % (rev_weapons[elite].size());
            string weapon = rev_weapons[elite][x];
            if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                x = rand() % (rev_offweapons[elite].size());
                weapon = weapon + "-" + rev_offweapons[elite][x];
            }
            weapons.push_back(weapon);
        }
    } else {

        vector<string> utilities;

        cout << "Skills: " << endl;
        cout << "Heal Skill: ";
        if (profession.compare("Guardian") == 0) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << guard_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = guard_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << guard_eliteskills[elite][x] << endl;


            while (weapons.size() < 2) {
                x = rand() % (guard_weapons[elite].size());
                string weapon = guard_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (guard_offweapons[elite].size());
                    weapon = weapon + "-" + guard_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }
        }  else if (profession.compare("Warrior") == 0) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << war_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = war_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << war_eliteskills[elite][x] << endl;


            while (weapons.size() < 2) {
                x = rand() % (war_weapons[elite].size());
                string weapon = war_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (war_offweapons[elite].size());
                    weapon = weapon + "-" + war_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }
        } else if (profession.compare("Engineer") == 0) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << engi_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = engi_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << engi_utilityskills[elite][x] << endl;


            while (weapons.size() < 2) {
                x = rand() % (engi_weapons[elite].size());
                string weapon = engi_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (engi_offweapons[elite].size());
                    weapon = weapon + "-" + engi_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }
        } else if (profession.compare("Ranger") == 0) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << rang_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = rang_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << rang_eliteskills[elite][x] << endl;


            while (weapons.size() < 2) {
                x = rand() % (rang_weapons[elite].size());
                string weapon = rang_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (rang_offweapons[elite].size());
                    weapon = weapon + "-" + rang_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }
        } else if (profession.compare("Thief") == 0) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << thief_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = thief_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << thief_eliteskills[elite][x] << endl;


            while (weapons.size() < 2) {
                x = rand() % (thief_weapons[elite].size());
                string weapon = thief_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (thief_offweapons[elite].size());
                    weapon = weapon + "-" + thief_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }
        } else if (profession.compare("Elementalist") == 0) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << ele_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = ele_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << ele_eliteskills[elite][x] << endl;


            while (weapons.size() < 1) {
                x = rand() % (ele_weapons[elite].size());
                string weapon = ele_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (ele_offweapons[elite].size());
                    weapon = weapon + "-" + ele_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }
        } else if (profession.compare("Mesmer") == 0) {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << mes_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = mes_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << mes_eliteskills[elite][x] << endl;


            while (weapons.size() < 2) {
                x = rand() % (mes_weapons[elite].size());
                string weapon = mes_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (mes_offweapons[elite].size());
                    weapon = weapon + "-" + mes_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }

        } else {
            if (active_elite) {
                x = rand() % 5;
            } else {
                x = rand() % 4;
            }

            cout << necro_healskills[elite][x] << endl;

            cout << "Utility Skills: ";

            while (utilities.size() < 3) {
                if (active_elite) {
                    x = rand() % 24;
                } else {
                    x = rand() % 20;
                }

                string utilskill = necro_utilityskills[elite][x];

                if (find(utilities.begin(), utilities.end(), utilskill) == utilities.end()) {
                    utilities.push_back(utilskill);
                }
            }

            for (int i = 0; i < utilities.size(); i++) {
                cout << utilities[i];
                if (i != 2) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "Elite Skill: ";

            if (active_elite) {
                x = rand() % 4;
            } else {
                x = rand() % 3;
            }

            cout << necro_eliteskills[elite][x] << endl;


            while (weapons.size() < 2) {
                x = rand() % (necro_weapons[elite].size());
                string weapon = necro_weapons[elite][x];
                if (find(main_wpns.begin(), main_wpns.end(), weapon) != main_wpns.end()) {
                    x = rand() % (necro_offweapons[elite].size());
                    weapon = weapon + "-" + necro_offweapons[elite][x];
                }
                weapons.push_back(weapon);
            }
        }
    }

    cout << "================================================================" << endl;
    if (profession.compare("Elementalist") == 0) {
        cout << "Weapons: " << weapons[0] << endl;
    } else {
        cout << "Weapons: " << weapons[0] << ", " << weapons[1] << endl;
    }

    cout << "================================================================" << endl;
    cout << "Attribute Combos:" << endl;

    x = rand() % (attribute_combos.size());
    cout << "Helm- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Shoulders- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Chest- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Gloves- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Leggings- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Boots- " << attribute_combos[x] << endl;
    cout << "------" << endl;
    x = rand() % (attribute_combos.size());
    cout << "Weapon Set 1- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Weapon Set 2- " << attribute_combos[x] << endl;
    cout << "------" << endl;
    x = rand() % (attribute_combos.size());
    cout << "Back Item- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Amulet- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Ring 1- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Ring 2- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Accessory 1- " << attribute_combos[x] << endl;
    x = rand() % (attribute_combos.size());
    cout << "Accessory 2- " << attribute_combos[x] << endl;

    cout << "================================================================" << endl;
    cout << "Runes: " << endl;
    x = rand() % (runes_list.size());
    cout << "Helm- " << runes_list[x] << endl;
    x = rand() % (runes_list.size());
    cout << "Shoulders- " << runes_list[x] << endl;
    x = rand() % (runes_list.size());
    cout << "Chest- " << runes_list[x] << endl;
    x = rand() % (runes_list.size());
    cout << "Gloves- " << runes_list[x] << endl;
    x = rand() % (runes_list.size());
    cout << "Leggings- " << runes_list[x] << endl;
    x = rand() % (runes_list.size());
    cout << "Boots- " << runes_list[x] << endl;
    cout << "------" << endl;

    cout << "Sigils: " << endl;
    cout << "Weapon Set 1- ";
    x = rand() % (sigil_list.size());
    cout << sigil_list[x] << ", ";
    x = rand() % (sigil_list.size());
    cout << sigil_list[x] << endl;
    cout << "Weapon Set 2- ";
    x = rand() % (sigil_list.size());
    cout << sigil_list[x] << ", ";
    x = rand() % (sigil_list.size());
    cout << sigil_list[x] << endl;

    cout << "================================================================" << endl;
    
}
