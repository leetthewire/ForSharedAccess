
// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
    elapsedTime;
    float time = float(timer.GetTotalSeconds());


    RECT WindowRect;
    GetClientRect(m_window, &WindowRect);
    MapWindowPoints(m_window, NULL, (LPPOINT)&WindowRect, 2);
    if (ActiveApp)
    {
        GetCursorPos(&CursorPos);
		// WindowRect.right - (m_outputWidth / 2)) Eto dlya centralizacii mouse
        PosToCameraAngle.x += (CursorPos.x - (WindowRect.right - (m_outputWidth / 2))) * 0.1;

        PosToCameraAngle.z += (CursorPos.y - (WindowRect.bottom - (m_outputHeight / 2))) * 0.1;

        if (PosToCameraAngle.z < -89)
            PosToCameraAngle.z = -89;
        if (PosToCameraAngle.z > 89)
            PosToCameraAngle.z = 89;

        if (PosToCameraAngle.x > 180)
            PosToCameraAngle.x = -179.999;
        if (PosToCameraAngle.x < -180)
            PosToCameraAngle.x = 179.999;
        
        PosToCameraAngle.y = PosToCameraAngle.x;

        if (PosToCameraAngle.z > 180)
            PosToCameraAngle.z = -179.999;
        if (PosToCameraAngle.z < -180)
            PosToCameraAngle.z = 179.999;


        AngleCameraX = cos(PosToCameraAngle.x * XM_PI / 180); //znachenie ot 0 do 1
        AngleCameraY = sin(PosToCameraAngle.y * XM_PI / 180); //znachenie ot 0 do 1
        AngleCameraZ = -tan(PosToCameraAngle.z * XM_PI / 180); //znachenie ot 0 do 1

		//vozvrashaem kursor v center
        SetCursorPos(WindowRect.right - (m_outputWidth / 2), WindowRect.bottom - (m_outputHeight / 2));

        //position control dlya input keyboard
        {
            if (m_pos.m_keyA) 
            {
                m_pos.posX += AngleCameraY;
                m_pos.posY -= AngleCameraX;
            }
            if (m_pos.m_keyW)
            {
                m_pos.posX += AngleCameraX;
                m_pos.posY += AngleCameraY;
            }
            if (m_pos.m_keyD)
            {
                m_pos.posX -= AngleCameraY;
                m_pos.posY += AngleCameraX;
            }
            if (m_pos.m_keyS)
            {
                m_pos.posX -= AngleCameraX;
                m_pos.posY -= AngleCameraY;
            }

            if (m_pos.m_keyUp)
            {
                m_pos.posZ++;
            }

            if (m_pos.m_keyDown)
            {
                m_pos.posZ--;
            }

            if (m_pos.m_keyZero)
            {
                m_pos.posX = 0;
                m_pos.posY = 0;
            }
        }
    }

	//Sama matriza zdes.
    m_view = Matrix::CreateLookAt(Vector3(m_pos.posX, m_pos.posZ+0.1f, m_pos.posY),
        Vector3(AngleCameraX + m_pos.posX, AngleCameraZ + m_pos.posZ, AngleCameraY + m_pos.posY), Vector3::UnitY);

}
