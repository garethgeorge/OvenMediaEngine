//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Hyunjun Jang
//  Copyright (c) 2019 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

namespace cfg
{
	namespace bind
	{
		namespace pub
		{
			struct Signalling : public Item
			{
				explicit Signalling(const char *port)
					: _port(port)
				{
				}

				Signalling(const char *port, const char *tls_port)
					: _port(port),
					  _tls_port(tls_port)
				{
				}

				CFG_DECLARE_REF_GETTER_OF(GetPort, _port);
				CFG_DECLARE_REF_GETTER_OF(GetTlsPort, _tls_port);
				CFG_DECLARE_REF_GETTER_OF(GetWorker, _worker);

			protected:
				void MakeParseList() override
				{
					RegisterValue<Optional>("Port", &_port);
					RegisterValue<Optional>("TLSPort", &_tls_port);
					RegisterValue<Optional>("Worker", &_worker);
				}

				cmn::SingularPort _port;
				cmn::SingularPort _tls_port;
				int _worker = 4;
			};
		}  // namespace pub
	}	   // namespace bind
}  // namespace cfg