Import-Module F:\Projects\InteractiveGraphics\Output\Release\InteractiveGraphics.Lib.dll                                                                                                                                                                           

Open-IGWindow                                                                                                                                                                                                                                                      

Clear-IGState

Set-IGWindow -Title 'Hi there' -Width 800 -Height 600 -ShowFPS $true   

# Create a nice blue/black sky gradient
New-IGLinearGradientBrush -NameOfBrush 'Sky'                                                                                                                                                                                                                       
Add-IGGradientStop 'Sky' -Offset 0 -Color '#114'                                                                                                                                                                                                                   
Add-IGGradientStop 'Sky' -Offset 1 -Color '#44F'  
                                                                                                                                                                                                                            
# Draw the sky
New-IGFilledRectangle '0_Sky' -NameOfBrush 'Sky' -X 0 -Y 0 -Width 800 -Height 600                                                                                                                                                                                      

# Draw the UFO
New-IGBitmap '1_Ufo'                                                                                                                                                                                                                                         

$deg2rad = (2 * [System.Math]::PI) / 360

foreach($i in 0..360)
{
    $x = $i
    $y = 100 * [System.Math]::Sin($i * $deg2rad * 4)
    Set-IGObject '1_Ufo' -X $x -Y $y
    Wait-IGStateIsPresented
}