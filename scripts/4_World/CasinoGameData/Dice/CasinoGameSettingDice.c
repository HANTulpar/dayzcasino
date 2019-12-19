class CasinoGameSettingDice extends CasinoGameSetting
{
    int minBet        = 10;
    int maxBet        = 10000;
    int diceWinFactor = 2;

    void CasinoGameSettingDice()
    {
        gameType = DAYZ_CASINO_TYPE_DICE_GAME;
        gamePositions = new array<ref GamePosition>;
        gamePositions.Insert(new GamePosition("8345.300781 293.181458 5976.666504", "4.999999 0.000000 0.000000"));
    }


}