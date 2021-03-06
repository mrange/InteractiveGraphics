# Imports Interactive Graphics commands
Import-Module 'F:\Projects\InteractiveGraphics\Output\Release\InteractiveGraphics.Lib.dll'

# Open the graphics window
Open-IGWindow

# Clears the windows
Clear-IGState

# Set the size of the window to something well-known
Set-IGWindow -Width 1024 -Height 768

# Create a sky gradient
New-IGLinearGradientBrush "Sky"                                                                                                                                                                                                                               
Add-IGGradientStop "Sky" -Offset 0 -Color "#004"                                                                                                                                                                                                              
Add-IGGradientStop "Sky" -Offset 1 -Color "#44F"                                                                                                                                                                                                              

# Draw the sky
New-IGFilledRectangle -NameOfBrush "Sky"  -X 0 -Y 0 -Width 1024 -Height 768                                                                                                                                                                                   

# Draw the ufo
New-IGBitmap "Ufo"                                                                                                                                                                                                                                            

$max_x = 320

# This for loops shows and ufo moving from left to right while bouncing up and down
foreach($i in 0..$max_x)
{
    $x = $i
    $y = 100 + 100 * [System.Math]::Sin(4* $i * 2 * [System.Math]::PI / $max_x)
    Set-IGObject "Ufo" -X $x -Y $y
    Wait-IGStateIsPresented
    
}
