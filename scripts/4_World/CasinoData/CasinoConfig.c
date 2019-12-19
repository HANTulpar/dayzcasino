class CasinoConfig
{
	const static string			CONFIGSFOLDER			= "$profile:ModConfigs\\";
	const static string			SETTINGSFILE			= "CasinoConfigV2.json";

	ref CasinoGameSettingLuckyWheel luckyWheelSettings;
	ref CasinoGameSettingBlackjack blackJackSettings;
	ref CasinoGameSettingDice diceSettings;
	ref CasinoGameSettingRatRace ratRaceSettings;

    void CasinoConfig()
    {
        Load();

		bool needs_save = false;

		// Create Default Casino World Objects
		if (CasinoMachines.Count() == 0)
		{
			diceSettings		= new CasinoGameSettingDice();
			blackJackSettings	= new CasinoGameSettingBlackjack();
			luckyWheelSettings = new CasinoGameSettingLuckyWheel();
            ratRaceSettings = new CasinoGameSettingRatRace();

			needs_save = true;
		}

		if (needs_save) Save();
    }

	private void Load()
	{
		if (IsServerAndMultiplayerCasino())
		{
			if (FileExist(CONFIGSFOLDER + SETTINGSFILE))
			{
				JsonFileLoader<CasinoConfig>.JsonLoadFile(CONFIGSFOLDER + SETTINGSFILE, this);
			}
			else
			{
				if (!FileExist(CONFIGSFOLDER))
				{
					MakeDirectory(CONFIGSFOLDER);
					Print("Creating ModConfigs Directory in Profile");
				}

				Create();
			}
		}
	}

    void Save()
    {
		if (IsServerAndMultiplayerCasino())
			JsonFileLoader<CasinoConfig>.JsonSaveFile(CONFIGSFOLDER + SETTINGSFILE, this);
    }

    private void Create()
    {
		if (IsServerAndMultiplayerCasino())
		{
			Save();
			Load();
		}
    }
}